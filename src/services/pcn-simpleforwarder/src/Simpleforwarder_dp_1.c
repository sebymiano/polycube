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

static __always_inline int handle_rx(struct CTXTYPE *ctx,
                                     struct pkt_metadata *md) {
#ifdef POLYCUBE_XDP
  pcn_log(ctx, LOG_TRACE, "XDP Cube", md->in_port);
#endif
  pcn_log(ctx, LOG_TRACE, "Receiving packet from port %d of microCube _NEXT_HOP", md->in_port);

  call_ingress_program(ctx, _NEXT_HOP);

  return RX_DROP;
}
