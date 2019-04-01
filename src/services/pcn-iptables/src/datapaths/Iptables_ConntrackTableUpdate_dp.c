/*
 * Copyright 2017 The Polycube Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* ===========================================
   LABEL the packet with the connection status
   =========================================== */

#include <uapi/linux/ip.h>
#include <uapi/linux/netfilter.h>
#include <uapi/linux/bpf.h>


#define ICMP_ECHOREPLY 0       /* Echo Reply			*/
#define ICMP_ECHO 8            /* Echo Request			*/
#define ICMP_TIMESTAMP 13      /* Timestamp Request		*/
#define ICMP_TIMESTAMPREPLY 14 /* Timestamp Reply		*/
#define ICMP_INFO_REQUEST 15   /* Information Request		*/
#define ICMP_INFO_REPLY 16     /* Information Reply		*/
#define ICMP_ADDRESS 17        /* Address Mask Request		*/
#define ICMP_ADDRESSREPLY 18   /* Address Mask Reply		*/

// ns
#define UDP_ESTABLISHED_TIMEOUT 180000000000
#define UDP_NEW_TIMEOUT 30000000000
#define ICMP_TIMEOUT 30000000000
#define TCP_ESTABLISHED 432000000000000
#define TCP_SYN_SENT 120000000000
#define TCP_SYN_RECV 60000000000
#define TCP_LAST_ACK 30000000000
#define TCP_FIN_WAIT 120000000000
#define TCP_TIME_WAIT 120000000000

#define TCPHDR_FIN 0x01
#define TCPHDR_SYN 0x02
#define TCPHDR_RST 0x04
#define TCPHDR_ACK 0x10

#define HEX_BE_ONE 0x1000000

#define AF_INET 2 /* Internet IP Protocol 	*/

struct icmphdr {
  u_int8_t type; /* message type */
  u_int8_t code; /* type sub-code */
  u_int16_t checksum;
  union {
    struct {
      u_int16_t id;
      u_int16_t sequence;
    } echo;            /* echo datagram */
    u_int32_t gateway; /* gateway address */
    struct {
      u_int16_t __unused;
      u_int16_t mtu;
    } frag; /* path mtu discovery */
  } un;
};

enum {
  NEW,
  ESTABLISHED,
  RELATED,
  INVALID,
  SYN_SENT,
  SYN_RECV,
  FIN_WAIT_1,
  FIN_WAIT_2,
  LAST_ACK,
  TIME_WAIT1
};

struct packetHeaders {
  uint32_t srcIp;
  uint32_t dstIp;
  uint8_t l4proto;
  uint16_t srcPort;
  uint16_t dstPort;
  uint8_t flags;
  uint32_t seqN;
  uint32_t ackN;
  uint8_t connStatus;
};

struct ct_k {
  uint32_t srcIp;
  uint32_t dstIp;
  uint8_t l4proto;
  uint16_t srcPort;
  uint16_t dstPort;
} __attribute__((packed));

struct ct_v {
  uint64_t ttl;
  uint8_t state;
  uint8_t ipRev;
  uint8_t portRev;
  uint32_t sequence;
} __attribute__((packed));

#if _INGRESS_LOGIC
BPF_TABLE_SHARED("percpu_array", int, uint64_t, timestamp, 1);
BPF_DEVMAP(tx_port, 128);
#endif

#if _EGRESS_LOGIC
BPF_TABLE("extern", int, uint64_t, timestamp, 1);
#endif

BPF_TABLE("extern", struct ct_k, struct ct_v, connections, 65536);

BPF_TABLE("extern", int, struct packetHeaders, packet, 1);

/* from include/net/ip.h */
static __always_inline int ip_decrease_ttl(struct iphdr *iph) {
  u32 check = (__force u32)iph->check;

  check += (__force u32)htons(0x0100);
  iph->check = (__force __sum16)(check + (check >= 0xFFFF));
  return --iph->ttl;
}

static __always_inline uint64_t *time_get_ns() {
  int key = 0;
  return timestamp.lookup(&key);
}

static int handle_rx(struct CTXTYPE *ctx, struct pkt_metadata *md) {
// Conntrack DISABLED
#if _CONNTRACK_MODE == 0
  return RX_OK;

#else
  // Conntrack ENABLED
  struct packetHeaders *pkt;
  int k = 0;
  struct bpf_conntrack_info info;
  pkt = packet.lookup(&k);

  if (pkt == NULL) {
    // Not possible
    return RX_DROP;
  }

  pcn_log(ctx, LOG_DEBUG,
          "[ConntrackTableUpdate] received packet. SrcIP: %I, Flags: %x",
          pkt->srcIp, pkt->flags);
  pcn_log(ctx, LOG_DEBUG,
          "[ConntrackTableUpdate] received packet. SeqN: %u, AckN: %u. "
          "ConnStatus: %u",
          pkt->seqN, pkt->ackN, pkt->connStatus);

  if (pkt->connStatus == INVALID) {
    // No business here for these packets
    goto forward_action;
  }

  __builtin_memset(&info, 0x0, sizeof(info));
  info.zone_id = 0x10;
  info.family = NFPROTO_IPV4;
  info.mark_value = 0x00009487;
  info.mark_mask = 0x0000ffff;

  	/* commit this skb to conntrack
	 * so the other direction (icmp echo reply) can pass
	 */
	int ret = bpf_skb_ct_commit(ctx, &info, 0);
	if (ret < 0) {
		pcn_log(ctx, LOG_DEBUG, "CT_COMMIT failed");
		return TC_ACT_OK;
	}

	pcn_log(ctx, LOG_DEBUG, "CT_COMMIT: zone: %d state: %d mark: %x", info.zone_id, info.ct_state, info.mark_value);
	goto forward_action;

forward_action:;

// FIB_LOOKUP_ENABLED is replaced a runtime by control plane
// true: if kernel >= 4.19.0 && XDP mode
#if _FIB_LOOKUP_ENABLED

#if _INGRESS_LOGIC

  // use fib_lookup helper to redirect pkt to egress interface directly (if
  // possible)

  // re-parse pkt is more convinient than parse it at pipeline beginning.
  // furthermore it is needed, since we have to change the packet

  void *data = (void *)(long)ctx->data;
  void *data_end = (void *)(long)ctx->data_end;
  struct bpf_fib_lookup fib_params;
  struct ethhdr *eth = data;
  struct ipv6hdr *ip6h;
  struct iphdr *iph;
  u16 h_proto;
  u64 nh_off;
  int rc;

  nh_off = sizeof(*eth);
  if (data + nh_off > data_end)
    return XDP_DROP;

  __builtin_memset(&fib_params, 0, sizeof(fib_params));

  h_proto = eth->h_proto;
  if (h_proto == htons(ETH_P_IP)) {
    iph = data + nh_off;

    if (iph + 1 > data_end)
      return XDP_DROP;

    if (iph->ttl <= 1)
      return XDP_PASS;

    fib_params.family = AF_INET;
    fib_params.tos = iph->tos;
    fib_params.l4_protocol = iph->protocol;
    fib_params.sport = 0;
    fib_params.dport = 0;
    fib_params.tot_len = ntohs(iph->tot_len);
    fib_params.ipv4_src = iph->saddr;
    fib_params.ipv4_dst = iph->daddr;
  } else {
    return RX_OK;
  }

  fib_params.ifindex = ctx->ingress_ifindex;

  rc = bpf_fib_lookup(ctx, &fib_params, sizeof(fib_params), 0);

  /* verify egress index has xdp support
   * TO-DO bpf_map_lookup_elem(&tx_port, &key) fails with
   *       cannot pass map_type 14 into func bpf_map_lookup_elem#1:
   * NOTE: without verification that egress index supports XDP
   *       forwarding packets are dropped.
   */
  if (rc == 0) {
    if (h_proto == htons(ETH_P_IP))
      ip_decrease_ttl(iph);

    memcpy(eth->h_dest, fib_params.dmac, ETH_ALEN);
    memcpy(eth->h_source, fib_params.smac, ETH_ALEN);

    pcn_log(
        ctx, LOG_TRACE,
        "Conntrack Table Update +bpf_fib_lookup+ redirect pkt to ifindex %d ",
        fib_params.ifindex);
    return tx_port.redirect_map(fib_params.ifindex, 0);

  } else {
    pcn_log(ctx, LOG_TRACE,
            "Conntrack Table Update INGRESS: ACCEPT packet, after save in "
            "session table");
    return RX_OK;
  }
#endif

#if _EGRESS_LOGIC
  pcn_log(ctx, LOG_TRACE,
          "Conntrack Table Update EGRESS: ACCEPT packet, after save in session "
          "table");
  return RX_OK;
#endif

#else
  pcn_log(ctx, LOG_TRACE,
          "Conntrack Table Update: ACCEPT packet, after save in session table");
  return RX_OK;
#endif

#endif
}