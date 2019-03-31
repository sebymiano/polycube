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

/* =======================
     Chain Forarder
   ======================= */

#include <uapi/linux/ip.h>
#include <uapi/linux/bpf.h>

#define AF_INET 2 /* Internet IP Protocol 	*/

struct elements {
  uint64_t bits[_MAXRULES];
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

BPF_TABLE("extern", int, struct elements, sharedEle, 1);

BPF_TABLE("extern", int, struct packetHeaders, packet, 1);

#if _INGRESS_LOGIC
BPF_TABLE_SHARED("hash", __be32, int, localip, 256);

BPF_TABLE("extern", int, u64, pkts_default_Input, 1);
BPF_TABLE("extern", int, u64, bytes_default_Input, 1);

BPF_TABLE("extern", int, u64, pkts_default_Forward, 1);
BPF_TABLE("extern", int, u64, bytes_default_Forward, 1);
#endif

#if _EGRESS_LOGIC
BPF_TABLE("extern", __be32, int, localip, 256);

BPF_TABLE("extern", int, u64, pkts_default_Output, 1);
BPF_TABLE("extern", int, u64, bytes_default_Output, 1);
#endif

// This is the percpu array containing the forwarding decision. ChainForwarder
// just lookup this value.
#if _INGRESS_LOGIC
BPF_TABLE_SHARED("percpu_array", int, int, forwardingDecision, 1);
#endif

#if _EGRESS_LOGIC
BPF_TABLE("extern", int, int, forwardingDecision, 1);
#endif

#if _INGRESS_LOGIC
static __always_inline void incrementDefaultCountersInput(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_default_Input.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_default_Input.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}

static __always_inline void incrementDefaultCountersForward(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_default_Forward.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_default_Forward.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}
#endif

#if _EGRESS_LOGIC
static __always_inline void incrementDefaultCountersOutput(u32 bytes) {
  u64 *value;
  int zero = 0;
  value = pkts_default_Output.lookup(&zero);
  if (value) {
    *value += 1;
  }

  value = bytes_default_Output.lookup(&zero);
  if (value) {
    *value += bytes;
  }
}
#endif

static __always_inline void updateForwardingDecision(int decision) {
  int key = 0;
  forwardingDecision.update(&key, &decision);
}

static int handle_rx(struct CTXTYPE *ctx, struct pkt_metadata *md) {
  pcn_log(ctx, LOG_DEBUG, "Code ChainSelector receiving packet.");

// No rules in INPUT and FORWARD chain, and default action is accept
// let all the traffic to be labeled and pass.
#if _INGRESS_ALLOWLOGIC
  pcn_log(ctx, LOG_DEBUG,
          "INGRESS LOGIC PASS. No rules for INPUT and FORWARD, and default is "
          "ACCEPT. ");
  updateForwardingDecision(PASS_LABELING);
  call_bpf_program(ctx, _CONNTRACK_LABEL_INGRESS);
#endif

  int key = 0;
  struct elements *result;

  struct packetHeaders *pkt;
  pkt = packet.lookup(&key);

  if (pkt == NULL) {
    // Not possible
    return RX_DROP;
  }

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

#if _INGRESS_LOGIC
  rc = bpf_fib_lookup(ctx, &fib_params, sizeof(fib_params), BPF_FIB_LOOKUP_DIRECT);
  pcn_log(ctx, LOG_DEBUG, "FIB_LOOKUP on INGRESS returned: %d", rc);

  if (rc == BPF_FIB_LKUP_RET_NOT_FWDED) {
    /* Packet is destined to local ip, we can redirect it to the INPUT chain
     * I am not sure this logic is totally sure, because looking at the code
     * of the helper we can see that error code is returned even with other
     * errors and not one when the packet matches a local entry.
     */
     pcn_log(ctx, LOG_DEBUG, "INGRESS Chain Selector. Dst ip matched. -->INPUT chain.");
     goto INPUT;
  } else if ((rc == BPF_FIB_LKUP_RET_BLACKHOLE) ||
             (rc == BPF_FIB_LKUP_RET_UNREACHABLE) ||
             (rc == BPF_FIB_LKUP_RET_PROHIBIT)) {
      pcn_log(ctx, LOG_DEBUG, "INGRESS Chain Selector. Dropping packet. ");
      return RX_DROP;
  } else {
    pcn_log(ctx, LOG_DEBUG, "INGRESS Chain Selector. Dst ip NOT matched. -->FORWARD chain.");
    goto FORWARD;
  }

INPUT:;
#if _NR_ELEMENTS_INPUT > 0
  result = sharedEle.lookup(&key);
  if (result == NULL) {
    // Not possible
    return RX_DROP;
  }
#if _NR_ELEMENTS_INPUT == 1
  (result->bits)[0] = 0x7FFFFFFFFFFFFFFF;
#else
#pragma unroll
  for (int i = 0; i < _NR_ELEMENTS_INPUT; ++i) {
    /*This is the first module, it initializes the percpu*/
    (result->bits)[i] = 0x7FFFFFFFFFFFFFFF;
  }

#endif
#endif
#if _NR_ELEMENTS_INPUT > 0
  // update map with INPUT_LABELING
  updateForwardingDecision(INPUT_LABELING);

  // call chain label INGRESS
  call_bpf_program(ctx, _CONNTRACK_LABEL_INGRESS);

#endif
  pcn_log(
      ctx, LOG_DEBUG,
      "No INPUT chain instantiated. Apply default action for INPUT chain. ");
  // PASS_LABELING if ACCEPT
  // DROP_NO_LABELING if DROP
  incrementDefaultCountersInput(md->packet_len);
  _DEFAULTACTION_INPUT
  call_bpf_program(ctx, _CONNTRACK_LABEL_INGRESS);

FORWARD:;
#if _NR_ELEMENTS_FORWARD > 0
  result = sharedEle.lookup(&key);
  if (result == NULL) {
    // Not possible
    return RX_DROP;
  }
#if _NR_ELEMENTS_FORWARD == 1
  (result->bits)[0] = 0x7FFFFFFFFFFFFFFF;
#else
#pragma unroll
  for (int i = 0; i < _NR_ELEMENTS_FORWARD; ++i) {
    /*This is the first module, it initializes the percpu*/
    (result->bits)[i] = 0x7FFFFFFFFFFFFFFF;
  }

#endif
#endif
#if _NR_ELEMENTS_FORWARD > 0
  // update map with FORWARD_LABELING
  updateForwardingDecision(FORWARD_LABELING);

  // call chain label INGRESS
  call_bpf_program(ctx, _CONNTRACK_LABEL_INGRESS);

#endif
  pcn_log(ctx, LOG_DEBUG,
          "No FORWARD chain instantiated. Apply default action for FORWARD "
          "chain. ");

  // PASS_LABELING if ACCEPT
  // DROP_NO_LABELING if DROP
  incrementDefaultCountersForward(md->packet_len);
  _DEFAULTACTION_FORWARD
  call_bpf_program(ctx, _CONNTRACK_LABEL_INGRESS);

#endif

#if _EGRESS_LOGIC
  //rc = bpf_fib_lookup(ctx, &fib_params, sizeof(fib_params), BPF_FIB_LOOKUP_OUTPUT);
  //pcn_log(ctx, LOG_DEBUG, "FIB_LOOKUP on EGRESS returned: %d", rc);

  __be32 srcip = pkt->srcIp;
  __be32 *ip_matched = localip.lookup(&srcip);

  // __be32* ip_matched = localip.lookup(&ip->saddr);
  if (ip_matched) {
    pcn_log(ctx, LOG_DEBUG,
            "EGRESS Chain Selector. Src ip matched. -->OUTPUT chain. ");
    goto OUTPUT;
  } else {
    pcn_log(ctx, LOG_DEBUG,
            "EGRESS Chain Selector. Src ip NOT matched. -->PASS. ");
    goto PASS;
  }

OUTPUT:;
#if _NR_ELEMENTS_OUTPUT > 0
  result = sharedEle.lookup(&key);
  if (result == NULL) {
    // Not possible
    return RX_DROP;
  }
#if _NR_ELEMENTS_OUTPUT == 1
  (result->bits)[0] = 0x7FFFFFFFFFFFFFFF;
#else
#pragma unroll
  for (int i = 0; i < _NR_ELEMENTS_OUTPUT; ++i) {
    /*This is the first module, it initializes the percpu*/
    (result->bits)[i] = 0x7FFFFFFFFFFFFFFF;
  }
#endif
#endif
#if _NR_ELEMENTS_OUTPUT > 0
  // update map with OUTPUT_LABELING
  updateForwardingDecision(OUTPUT_LABELING);

  // call chain label INGRESS
  call_bpf_program(ctx, _CONNTRACK_LABEL_EGRESS);
#endif
  pcn_log(
      ctx, LOG_DEBUG,
      "No OUTPUT chain instantiated. Apply default action for OUTPUT chain. ");

  // PASS_LABELING if ACCEPT
  // DROP_NO_LABELING if DROP
  incrementDefaultCountersOutput(md->packet_len);
  _DEFAULTACTION_OUTPUT
  call_bpf_program(ctx, _CONNTRACK_LABEL_EGRESS);

PASS:;
  pcn_log(ctx, LOG_DEBUG,
          "No hit for OUTPUT chain. Let the packet PASS_NO_LABELING. ");
  return RX_OK;

#endif

  return RX_DROP;
}