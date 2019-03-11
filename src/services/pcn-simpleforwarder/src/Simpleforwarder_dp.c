/*
 * Copyright 2018 The Polycube Authors
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

#include <bcc/helpers.h>
#include <bcc/proto.h>
#include <linux/in.h>
#include <linux/if_ether.h>

BPF_PERCPU_ARRAY(rxcnt, long, 1);

enum {
  SLOWPATH_REASON = 1
};
enum {
  DROP,     // drop packet
  SLOWPATH, // send packet to user-space
  FORWARD,  // send packe through a port
};
struct action {
  uint16_t action;  // which action? see above enum
  uint16_t port;    // in case of redirect, to what port?
};
/*
* Key is the ingress port an action is a struct that describes how to handle
* that packet.
*/
BPF_HASH(actions, uint16_t, struct action);

static __always_inline
void swap_src_dst_mac(void *data) {
    unsigned short *p = data;
    unsigned short dst[3];
    dst[0] = p[0];
    dst[1] = p[1];
    dst[2] = p[2];
    p[0] = p[3];
    p[1] = p[4];
    p[2] = p[5];
    p[3] = dst[0];
    p[4] = dst[1];
    p[5] = dst[2];
}

static __always_inline
int handle_rx(struct CTXTYPE *ctx, struct pkt_metadata *md) {
  #ifdef POLYCUBE_XDP
    pcn_log(ctx, LOG_TRACE, "XDP Cube", md->in_port);
  #endif
  pcn_log(ctx, LOG_TRACE, "Receiving packet from port %d", md->in_port);

  void* data_end = (void*)(long)ctx->data_end;
  void* data = (void*)(long)ctx->data;
  struct ethhdr *eth = data;
  uint32_t key = 0;
  long *value;
  uint64_t nh_off;
  nh_off = sizeof(*eth);
  if (data + nh_off  > data_end)
      return RX_DROP;

  value = rxcnt.lookup(&key);
  if (value)
      *value += 1;
  swap_src_dst_mac(data);
  if (md->in_port == 0)
    return pcn_pkt_redirect(ctx, md, 1);
  else
    return pcn_pkt_redirect(ctx, md, 0);
}

