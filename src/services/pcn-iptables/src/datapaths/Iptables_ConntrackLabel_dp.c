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
#include <uapi/linux/netfilter/nf_conntrack_common.h>

#define ICMP_ECHOREPLY 0       /* Echo Reply			*/
#define ICMP_ECHO 8            /* Echo Request			*/
#define ICMP_TIMESTAMP 13      /* Timestamp Request		*/
#define ICMP_TIMESTAMPREPLY 14 /* Timestamp Reply		*/
#define ICMP_INFO_REQUEST 15   /* Information Request		*/
#define ICMP_INFO_REPLY 16     /* Information Reply		*/
#define ICMP_ADDRESS 17        /* Address Mask Request		*/
#define ICMP_ADDRESSREPLY 18   /* Address Mask Reply		*/

#define TCPHDR_FIN 0x01
#define TCPHDR_SYN 0x02
#define TCPHDR_RST 0x04
#define TCPHDR_ACK 0x10

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
  INPUT_LABELING,    // goto input chain and label packet
  FORWARD_LABELING,  // goto forward chain and label packet
  OUTPUT_LABELING,   // goto output chain and label packet
  PASS_LABELING,     // one chain is hit (IN/PUT/FWD) but there are no rules and
                     // default action is accept. Label packet and let it pass.
  PASS_NO_LABELING,  // OUTPUT chain is not hit, let the packet pass without
                     // labeling //NEVER HIT
  DROP_NO_LABELING   // one chain is hit (IN/PUT/FWD) but there are no rules and
                     // default action is DROP. //NEVER HIT
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
BPF_TABLE_SHARED("lru_hash", struct ct_k, struct ct_v, connections, 65536);
#endif

#if _EGRESS_LOGIC
BPF_TABLE("extern", struct ct_k, struct ct_v, connections, 65536);
#endif

BPF_TABLE("extern", int, struct packetHeaders, packet, 1);
// BPF_TABLE("extern", int, struct packetHeaders, packetEgress, 1);

// This is the percpu array containing the forwarding decision. ChainForwarder
// just lookup this value.
BPF_TABLE("extern", int, int, forwardingDecision, 1);

static __always_inline int *getForwardingDecision() {
  int key = 0;
  return forwardingDecision.lookup(&key);
}

#if _INGRESS_LOGIC
BPF_TABLE_SHARED("percpu_array", int, u64, pkts_acceptestablished_Input, 1);
BPF_TABLE_SHARED("percpu_array", int, u64, bytes_acceptestablished_Input, 1);

BPF_TABLE_SHARED("percpu_array", int, u64, pkts_acceptestablished_Forward, 1);
BPF_TABLE_SHARED("percpu_array", int, u64, bytes_acceptestablished_Forward, 1);
#endif

#if _EGRESS_LOGIC
BPF_TABLE_SHARED("percpu_array", int, u64, pkts_acceptestablished_Output, 1);
BPF_TABLE_SHARED("percpu_array", int, u64, bytes_acceptestablished_Output, 1);
#endif

#if _INGRESS_LOGIC
static __always_inline void incrementAcceptEstablishedInput(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_acceptestablished_Input.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_acceptestablished_Input.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}

static __always_inline void incrementAcceptEstablishedForward(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_acceptestablished_Forward.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_acceptestablished_Forward.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}
#endif

#if _EGRESS_LOGIC
static __always_inline void incrementAcceptEstablishedOutput(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_acceptestablished_Output.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_acceptestablished_Output.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}
#endif

static int handle_rx(struct CTXTYPE *ctx, struct pkt_metadata *md) {
  pcn_log(ctx, LOG_DEBUG, "Conntrack label received packet");
  struct packetHeaders *pkt;
  int k = 0;
  struct bpf_conntrack_info info;

  pkt = packet.lookup(&k);

  if (pkt == NULL) {
    // Not possible
    return RX_DROP;
  }

  __builtin_memset(&info, 0x0, sizeof(info));
  info.zone_id = 0x10;
  info.family = NFPROTO_IPV4;

  int ret = bpf_skb_ct_lookup(ctx, &info, 0);
  if (ret < 0) {
      return RX_DROP;
  }

  pcn_log(ctx, LOG_DEBUG, "CT_LOOKUP: zone: %d state: %d mark: %x", info.zone_id, info.ct_state, info.mark_value);

  switch (info.ct_state) {
      case IP_CT_ESTABLISHED:
      case IP_CT_ESTABLISHED_REPLY:
          pkt->connStatus = ESTABLISHED;
          break;
      case IP_CT_RELATED:
      case IP_CT_RELATED_REPLY:
          pkt->connStatus = RELATED;
          break;
      case IP_CT_NEW:
          pkt->connStatus = NEW;
          break;
      default:
          pkt->connStatus = INVALID;
          break;
  }

  pcn_log(ctx, LOG_DEBUG, "PCN_IPT: conntrack_state %hu", pkt->connStatus);
  goto action;

action:;
  // TODO possible optimization, inject it if needed
  int *decision = getForwardingDecision();

  if (decision == NULL) {
    return RX_DROP;
  }

#if _INGRESS_LOGIC

  switch (*decision) {
  case INPUT_LABELING:
    pcn_log(ctx, LOG_DEBUG, "ConntrackLabel: INPUT_LABELING ");

#if _CONNTRACK_MODE_INPUT == 2
    goto DISABLED;
#elif _CONNTRACK_MODE_INPUT == 1
    if (pkt->connStatus == ESTABLISHED) {
      incrementAcceptEstablishedInput(md->packet_len);
      goto ENABLED_MATCH;
    } else {
      goto ENABLED_NOT_MATCH;
    }
#endif
    return RX_DROP;

  case FORWARD_LABELING:
    pcn_log(ctx, LOG_DEBUG, "ConntrackLabel: FORWARD_LABELING ");

#if _CONNTRACK_MODE_FORWARD == 2
    goto DISABLED;
#elif _CONNTRACK_MODE_FORWARD == 1
    if (pkt->connStatus == ESTABLISHED) {
      incrementAcceptEstablishedForward(md->packet_len);
      goto ENABLED_MATCH;
    } else {
      goto ENABLED_NOT_MATCH;
    }
#endif
    return RX_DROP;

  case PASS_LABELING:
    pcn_log(ctx, LOG_DEBUG, "ConntrackLabel: PASS_LABELING ");

    goto DISABLED;
    return RX_DROP;

  default:
    pcn_log(ctx, LOG_ERR, "ConntrackLabel Ingress: Something went wrong. ");
    return RX_DROP;
  }

#endif

#if _EGRESS_LOGIC

  switch (*decision) {
  case OUTPUT_LABELING:
    pcn_log(ctx, LOG_DEBUG, "ConntrackLabel: OUTPUT_LABELING ");

#if _CONNTRACK_MODE_OUTPUT == 2
    goto DISABLED;
#elif _CONNTRACK_MODE_OUTPUT == 1
    if (pkt->connStatus == ESTABLISHED) {
      incrementAcceptEstablishedOutput(md->packet_len);
      goto ENABLED_MATCH;
    } else {
      goto ENABLED_NOT_MATCH;
    }
#endif
    return RX_DROP;

  case PASS_LABELING:
    pcn_log(ctx, LOG_DEBUG, "ConntrackLabel: PASS_LABELING ");

    goto DISABLED;
    return RX_DROP;

  default:
    pcn_log(ctx, LOG_ERR, "ChainForwarder Egress: Something went wrong. ");
    return RX_DROP;
  }

#endif

DISABLED:;
  pcn_log(ctx, LOG_TRACE,
          "ConntrackLabel (Optimization OFF) Calling Chainforwarder %d",
          _CHAINFORWARDER);
  call_bpf_program(ctx, _CHAINFORWARDER);

  pcn_log(ctx, LOG_TRACE,
          "ConntrackLabel Calling Chainforwarder FAILED. Dropping");
  return RX_DROP;

ENABLED_MATCH:;
  // ON (Perform optimization for accept established)
  //  if established, forward directly
  pcn_log(ctx, LOG_TRACE,
          "ConntrackLabel (Optimization ON) ESTABLISHED Connection found. "
          "Calling ConntrackTableUpdate.");
  call_bpf_program(ctx, _CONNTRACKTABLEUPDATE);

  pcn_log(ctx, LOG_DEBUG, "[ConntrackLabel] Something went wrong.");
  return RX_DROP;

ENABLED_NOT_MATCH:;
  // ON (Perform optimization for accept established), but no match on
  // ESTABLISHED connection
  pcn_log(ctx, LOG_TRACE,
          "ConntrackLabel (Optimization ON) no connection found. Calling "
          "ChainForwarder.");
  call_bpf_program(ctx, _CHAINFORWARDER);

  pcn_log(ctx, LOG_DEBUG, "[ConntrackLabel] Something went wrong.");

  return RX_DROP;
}
