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

#include <linux/jhash.h>
#include <uapi/linux/bpf.h>
#include <uapi/linux/filter.h>
#include <uapi/linux/icmp.h>
#include <uapi/linux/if_arp.h>
#include <uapi/linux/if_ether.h>
#include <uapi/linux/if_packet.h>
#include <uapi/linux/in.h>
#include <uapi/linux/ip.h>
#include <uapi/linux/pkt_cls.h>
#include <uapi/linux/tcp.h>
#include <uapi/linux/udp.h>

/*
*
* This load balancer implements the following behavior:
*
*  - Load Balance (by looking up in the services map the VIP, to make load
* balancing)(from vip to backend)
*  - Reverse Proxy (from backend to vip)
*
*    IF (DADDR IS VIP)
*      LOAD BALANCE
*      REDIRECT TO BACKEND_PORT
*
*    ELSE IF(PKT FROM BACKEND_PORT)
*      REV_PROXY -> (SADDR = VIP)
*      REDIRECT TO FRONTEND_PORT
*    ELSE IF(PKT FROM FRONTEND_PORT)
*      REDIRECT TO BACKEND_PORT
*
*/

#define MAX_SERVICES 10000
#define MAX_SESSIONS 65536

#define IP_CSUM_OFFSET (sizeof(struct eth_hdr) + offsetof(struct iphdr, check))
#define TCP_CSUM_OFFSET                            \
  (sizeof(struct eth_hdr) + sizeof(struct iphdr) + \
   offsetof(struct tcphdr, check))
#define UDP_CSUM_OFFSET                            \
  (sizeof(struct eth_hdr) + sizeof(struct iphdr) + \
   offsetof(struct udphdr, check))
#define ICMP_CSUM_OFFSET                           \
  (sizeof(struct eth_hdr) + sizeof(struct iphdr) + \
   offsetof(struct icmphdr, checksum))
#define IS_PSEUDO 0x10

#ifndef SRCIP_REWRITE_ENABLED
#define SRCIP_REWRITE_ENABLED 0
#endif

#ifndef BACKEND_PORT
#define BACKEND_PORT 0
#endif

#ifndef FRONTEND_PORT
#define FRONTEND_PORT 0
#endif

struct eth_hdr {
  __be64 dst : 48;
  __be64 src : 48;
  __be16 proto;
} __attribute__((packed));

struct arp_hdr {
  __be16 ar_hrd;        /* format of hardware address	*/
  __be16 ar_pro;        /* format of protocol address	*/
  unsigned char ar_hln; /* length of hardware address	*/
  unsigned char ar_pln; /* length of protocol address	*/
  __be16 ar_op;         /* ARP opcode (command)		*/
  __be64 ar_sha : 48;   /* sender hardware address	*/
  __be32 ar_sip;        /* sender IP address		*/
  __be64 ar_tha : 48;   /* target hardware address	*/
  __be32 ar_tip;        /* target IP address		*/
} __attribute__((packed));

// This struct keeps the session ID of the traffic that has currently been
// handled by the load balancer.
// This is needed in order to perform the reverse proxy algorithm to the return
// traffic
struct sessions {
  __be32 ip_src;
  __be32 ip_dst;
  __be16 port_src;
  __be16 port_dst;
  __be16 proto;
} __attribute__((packed));

struct vip {
  __be32 ip;
  __be16 port;
  __be16 proto;
  __be16 index;  // refers to backend's index for that Service(vip)
} __attribute__((packed));

struct backend {
  __be32 ip;
  __be16 port;
  __be16 proto;
} __attribute__((packed));

/*
 * This table contains multiple entries for each virtual service (i.e., virtual
 * IP / protocol / port).
 * When 'index' = 0, the value in the hash map is actually not a couple
 *   IP address / port but the number of backends (also called 'pool size')
 *   associated to that virtual service.
 * Then, for following entries (i.e., when 'index' > 0), the
 *   'struct backend' keeps the actual data (IP/port) for that backend.
 *
 * Example:
 *   VIP 1, index 0 -> Number of backends: 4
 *   VIP 1, index 1 -> Backend 2
 *   VIP 1, index 2 -> Backend 1
 *   VIP 1, index 3 -> Backend 2
 *   VIP 1, index 4 -> Backend 1
 *
 *   VIP 2, index 0 -> Number of backends: 2
 *   VIP 2, index 1 -> Backend 1
 *   VIP 2, index 2 -> Backend 1
 *
 *   where VIP 1 has 4 backends and VIP2 has 2 backend.
 *
 * The number of backend in this table may be different from the number of
 * actual servers in order to keep session affinity when a server is
 * added/removed, without having to move the traffic from a backend#1
 * to a backend #2 (which will break the TCP session)
 *
 * The load balancing algorith will select the proper backend based on an hash
 * on the most significant fields (i.e., session id) of the packet:
 *
 *   __u32 backend_id = session_hash % pool_size + 1;
 *
 * where 'pool_size' is 4 for VIP 1.
 */
BPF_TABLE("percpu_hash", struct vip, struct backend, services, MAX_SERVICES);

/*
 *  Keeps the sessions handled by the load balancer in this table. This is
 *  needed to translate the session ID back for return traffic.
 *    __u32: key (hash the translated session: Hash(ipS | ipD=BCK | pS | pD |
 * pro) )
 *    struct vip: value (virtual service ID, to be used to translate
 *         the return traffic)
 *
 *  If there's a match, the (return) source IP address/port is translated with
 *  the VIP; if there is no match, the traffic is left untouched.
 *  Note that the hash is calculated, in both directions, using the IP.dst
 *  of the backend, not the original one (virtual IP address of the service).
 */
BPF_TABLE("lru_hash", __u32, struct vip, hash_session, MAX_SESSIONS);

enum {
  FROM_FRONTEND = 0,
  FROM_BACKEND = 1,
};

struct src_ip_r_key {
  u32 netmask_len;
  __be32 network;
};

struct src_ip_r_value {
  u32 sense;
  u32 net;   // host network byte order
  u32 mask;  // host network byte order
};

BPF_F_TABLE("lpm_trie", struct src_ip_r_key, struct src_ip_r_value,
            src_ip_rewrite, MAX_SERVICES, BPF_F_NO_PREALLOC);

BPF_TABLE("percpu_hash", struct backend, struct vip, backend_to_service, MAX_SERVICES);

/*
 * This function is used to get the backend ip after the LoadBalancing.
 * For each packet that handled by the load balancer, we save the hash of
 * the session in the session table, to be used for the return traffic
 * (reverse proxy).
 */
static inline struct backend *get_bck_ip(struct CTXTYPE *ctx, __be32 ip_src,
                                         __be32 ip_dst, __be16 port_src,
                                         __be16 port_dst, __be16 proto,
                                         __u32 pool_size) {
  // lookup in the sessions_table
  struct sessions sessions_key = {};
  sessions_key.ip_src = ip_src;
  sessions_key.ip_dst = ip_dst;
  sessions_key.port_src = port_src;
  sessions_key.port_dst = port_dst;
  sessions_key.proto = proto;

  if (!pool_size) {
    return 0;
  }

  // calculate the hashed session key
  u32 check = jhash((const void *)&sessions_key, sizeof(struct sessions),
                    JHASH_INITVAL);
  // select the backend id
  __u32 id = check % pool_size + 1;

  pcn_log(ctx, LOG_TRACE, "Selected backend with id: %d", id);

  struct vip v_key = {};

  v_key.ip = ip_dst;
  v_key.port = port_dst;
  v_key.proto = proto;
  v_key.index = id;

  pcn_log(ctx, LOG_TRACE,
          "Backend lookup ip: %I, port: %P, proto: 0x%04x, index: %d", ip_dst,
          port_dst, proto, id);

  // Now, from the backend ID, let's get the actual backend server (IP/port)
  struct backend *bck_value = services.lookup(&v_key);
  if (!bck_value) {
    return 0;
  }

  pcn_log(ctx, LOG_TRACE, "Found backend with ip: %I and port: %P",
          bck_value->ip, bck_value->port);

#if SRCIP_REWRITE_ENABLED
  // check if src ip rewrite applies for this packet, if yes,  do not create a
  // new entry in the session table
  struct src_ip_r_key k = {32, ip_dst};
  struct src_ip_r_value *v1 = src_ip_rewrite.lookup(&k);
  if (v1) {
    return bck_value;
  }
#endif

#if FRONTED_PORT != BACKEND_PORT
  // Calculate a second hash on the session, but this time we use the backend IP
  sessions_key.ip_dst = bck_value->ip;      // backend ip address
  sessions_key.port_dst = bck_value->port;  // backend port

  if (proto == ntohs(IPPROTO_ICMP)) {
    sessions_key.port_dst = port_dst;
    sessions_key.port_src = port_src;
  }
  check = jhash((const void *)&sessions_key, sizeof(struct sessions),
                JHASH_INITVAL);

  struct vip v = {};
  v.ip = ip_dst;
  v.port = port_dst;
  v.proto = proto;
  v.index = 0;

  // update the session table with this entry. If the entry already exists,
  // nothing happens.
  // if the entry doesn't exist, it is added to the list
  hash_session.update(&check, &v);  // hash-vip
#endif

  return bck_value;
}

static inline void checksum(struct CTXTYPE *ctx, __u16 old_port, __u16 new_port,
                            __u32 old_dip, __u32 new_dip, __u32 old_sip,
                            __u32 new_sip, __u32 flag) {
  pcn_l3_csum_replace(ctx, IP_CSUM_OFFSET, old_dip, new_dip, 4);
  pcn_l4_csum_replace(ctx, flag, old_port, new_port, 2);
  pcn_l4_csum_replace(ctx, flag, old_dip, new_dip, 4 | IS_PSEUDO);

  if (new_sip != 0) {
    pcn_l3_csum_replace(ctx, IP_CSUM_OFFSET, old_sip, new_sip, 4);
    pcn_l4_csum_replace(ctx, flag, old_sip, new_sip, 4 | IS_PSEUDO);
  }
}

static __always_inline int handle_rx(struct CTXTYPE *ctx,
                                     struct pkt_metadata *md) {
  __u16 source = 0;
  __u16 dest = 0;
  __u16 ip_proto = 0;
  __be32 l4csum_offset = 0;

  void *data = (void *)(long)ctx->data;
  void *data_end = (void *)(long)ctx->data_end;

  struct eth_hdr *eth = data;

  if (data + sizeof(*eth) > data_end)
    goto DROP;

  switch (eth->proto) {
  case htons(ETH_P_IP):
    goto IP;  // ipv4 packet
  case htons(ETH_P_ARP):
    goto ARP;  // arp packet
  default:
    goto NOIP;
  }

IP:;
  struct iphdr *ip = data + sizeof(struct eth_hdr);
  if (data + sizeof(struct eth_hdr) + sizeof(struct iphdr) > data_end)
    goto DROP;

  struct udphdr *udp = data + sizeof(struct eth_hdr) + sizeof(struct iphdr);
  struct tcphdr *tcp = data + sizeof(struct eth_hdr) + sizeof(struct iphdr);
  struct icmphdr *icmp = data + sizeof(struct eth_hdr) + sizeof(struct iphdr);

  __u32 old_ip = ip->daddr;
  __u32 new_ip = ip->daddr;
  __u32 old_sip = ip->saddr;
  __u32 new_sip = 0;

  switch (ip->protocol) {
  case IPPROTO_ICMP:
    goto ICMP;
  case IPPROTO_UDP:
    goto UDP;
  case IPPROTO_TCP:
    goto TCP;
  default:
    goto DROP;
  }

ICMP:
  if (data + sizeof(*eth) + sizeof(*ip) + sizeof(*icmp) > data_end)
    return RX_DROP;

  // Only manage ICMP Request and Reply
  if (!((icmp->type == ICMP_ECHO) || (icmp->type == ICMP_ECHOREPLY)))
    goto DROP;

  source = icmp->un.echo.id;
  dest = 0x0;
  ip_proto = htons(IPPROTO_ICMP);

  pcn_log(ctx, LOG_DEBUG, "received ICMP %I --> %I", ip->saddr, ip->daddr);

  l4csum_offset = ICMP_CSUM_OFFSET;
  goto LB;

UDP:
  if (data + sizeof(*eth) + sizeof(*ip) + sizeof(*udp) > data_end)
    return RX_DROP;

  pcn_log(ctx, LOG_TRACE, "received UDP: %I:%P --> %I:%P", ip->saddr,
          udp->source, ip->daddr, udp->dest);

  source = udp->source;
  dest = udp->dest;
  ip_proto = htons(IPPROTO_UDP);

  l4csum_offset = UDP_CSUM_OFFSET;
  goto LB;

TCP:
  if (data + sizeof(*eth) + sizeof(*ip) + sizeof(*tcp) > data_end)
    return RX_DROP;

  pcn_log(ctx, LOG_TRACE, "received TCP: %I:%P --> %I:%P", ip->saddr,
          tcp->source, ip->daddr, tcp->dest);

  source = tcp->source;
  dest = tcp->dest;
  ip_proto = htons(IPPROTO_TCP);

  l4csum_offset = TCP_CSUM_OFFSET;
  goto LB;

LB:;

  __u32 old_port = dest;
  __u32 new_port = dest;

  // Currently, the "backend port" is the one connected to the backends
  // So, this packet is coming from the fronted and is returning back to the
  // originating Pod.

  if (md->in_port == FRONTEND_PORT) {
    pcn_log(ctx, LOG_TRACE, "Packet arrived in the frontend port");

    struct vip v_key = {};

    v_key.ip = ip->daddr;
    v_key.port = dest;
    v_key.proto = ip_proto;
    v_key.index = 0;

    // Look for the destination IP address in the map (with index=0)
    // If there's a match, it means this is a VIP, so we need to apply the LB
    // logic
    // If doesn't match, just send the packet as is (no need to load balance)
    struct backend *backend_value = services.lookup(&v_key);
    // The IP destination address is not a virtual service. Let's forward the
    // packet as is.
    if (!backend_value) {
      pcn_log(ctx, LOG_TRACE,
              "Service lookup failed. Redirected as is to backend port");
      return pcn_pkt_redirect(ctx, md, BACKEND_PORT);
    }

    // Return the proper backend for this packet
    struct backend *bck_value = get_bck_ip(ctx, ip->saddr, ip->daddr, source,
                                           dest, ip_proto, backend_value->port);

    if (!bck_value) {
      goto DROP;
    }

    ip->daddr = bck_value->ip;

#if SRC_IP_REWRITE_ENABLED
    // should we rewrite the src ip?
    struct src_ip_r_key k = {32, ip->saddr};
    struct src_ip_r_value *v = src_ip_rewrite.lookup(&k);
    if (v && v->sense == FROM_FRONTEND) {
      ip->saddr &= bpf_htonl(v->mask);
      ip->saddr |= bpf_htonl(v->net);
      new_sip = ip->saddr;
      pcn_log(ctx, LOG_TRACE, "src ip rewritten to %I", ip->saddr);
    }
#endif

    pcn_log(ctx, LOG_TRACE, "redirected to %I:%P --> %I:%P", ip->saddr, source,
            bck_value->ip, bck_value->port);

    // We are using l4csum_offset here, since it is equivalent of the protocol
    if (l4csum_offset == TCP_CSUM_OFFSET) {
      tcp->dest = bck_value->port;
      checksum(ctx, old_port, bck_value->port, old_ip, bck_value->ip, old_sip,
               new_sip, TCP_CSUM_OFFSET);
    } else if (l4csum_offset == UDP_CSUM_OFFSET) {
      udp->dest = bck_value->port;
      checksum(ctx, old_port, bck_value->port, old_ip, bck_value->ip, old_sip,
               new_sip, UDP_CSUM_OFFSET);
    } else {
      pcn_log(ctx, LOG_TRACE, "translated existing ICMP session as %I --> %I",
              new_ip, ip->daddr);
      pcn_l3_csum_replace(ctx, IP_CSUM_OFFSET, old_ip, bck_value->ip, 4);
    }

    return pcn_pkt_redirect(ctx, md, BACKEND_PORT);
  } else {  // The packet is in its way back from the virtual servers. Coming
            // from the BACKEND port
            /*
            * if src is srrIpRewrite
            *     CHANGE
            * else
            *     SESSION TABLE
            */
    // IF FRONTED && BACKEND PORTS are equal, this code will never be executed
    pcn_log(ctx, LOG_TRACE, "Packet comes from backend port: %I", ip->daddr);

    __u32 dst_ip_ = ip->daddr;

    // Lookup into srcIpRewrite map by backend ip (ip->daddr)
    // Hit: change src -> VIP and dst -> bck_ip_old
    // Miss: check if it is in the session table
    struct src_ip_r_key k = {32, ip->daddr};
    struct src_ip_r_value *v = src_ip_rewrite.lookup(&k);
    if (v && v->sense == FROM_BACKEND) {
      struct backend key = {.ip = ip->saddr, .port = source, .proto = ip_proto};

      struct vip *vip_v = backend_to_service.lookup(&key);
      if (!vip_v) {
        pcn_log(ctx, LOG_ERR, "Reverse backend lookup failed");
        goto DROP;
      }

      old_ip = ip->daddr;
      old_sip = ip->saddr;
      ip->daddr &= bpf_htonl(v->mask);
      ip->daddr |= bpf_htonl(v->net);
      ip->saddr = vip_v->ip;

      new_sip = vip_v->ip;
      new_ip = ip->daddr;
      new_port = vip_v->port;
      pcn_log(
          ctx, LOG_TRACE,
          "srcIpRewrite found. translate ip src %I dst %I --> src %I dst %I",
          old_sip, old_ip, new_sip, new_ip);
    } else {
      struct sessions sessions_key = {};
      sessions_key.ip_src = ip->daddr;
      sessions_key.ip_dst = ip->saddr;
      sessions_key.port_src = dest;
      sessions_key.port_dst = source;
      sessions_key.proto = ip_proto;

      if (ip_proto == ntohs(IPPROTO_ICMP)) {
        sessions_key.port_dst = dest;
        sessions_key.port_src = source;
      }

      __u32 check = jhash((const void *)&sessions_key, sizeof(struct sessions),
                          JHASH_INITVAL);

      pcn_log(ctx, LOG_TRACE, "Check in session table %lu", check);

      // Let's check if the this session is present in the session table
      struct vip *rev_proxy = hash_session.lookup(&check);

      // If this (return) packet belongs to a session that was handled by the
      // LB,
      //    we have to  translate IP addresses back to their original value
      if (!rev_proxy) {
        pcn_log(ctx, LOG_TRACE, "redirected as is to frontend port");
        return pcn_pkt_redirect(ctx, md, FRONTEND_PORT);
      }

      old_ip = ip->saddr;
      ip->saddr = rev_proxy->ip;
      new_ip = rev_proxy->ip;
      new_port = rev_proxy->port;
    }

    if (l4csum_offset == TCP_CSUM_OFFSET) {
      old_port = tcp->source;
      tcp->source = new_port;
      pcn_log(ctx, LOG_TRACE,
              "translated existing TCP session as %I:%P --> %I:%P", new_ip,
              tcp->source, ip->daddr, dest);
      checksum(ctx, old_port, new_port, old_ip, new_ip, old_sip, new_sip,
               TCP_CSUM_OFFSET);
    } else if (l4csum_offset == UDP_CSUM_OFFSET) {
      old_port = udp->source;
      udp->source = new_port;
      pcn_log(ctx, LOG_TRACE,
              "translated existing UDP session as %I:%P --> %I:%P", new_ip,
              new_port, ip->daddr, dest);
      checksum(ctx, old_port, new_port, old_ip, new_ip, old_sip, new_sip,
               UDP_CSUM_OFFSET);
    } else {
      pcn_log(ctx, LOG_TRACE, "translated existing ICMP session as %I --> %I",
              new_ip, ip->daddr);
      pcn_l3_csum_replace(ctx, IP_CSUM_OFFSET, old_ip, new_ip, 4);
    }

    return pcn_pkt_redirect(ctx, md, FRONTEND_PORT);
  }

ARP:;
  struct arp_hdr *arp = data + sizeof(*eth);
  if (data + sizeof(*eth) + sizeof(*arp) > data_end)
    goto DROP;

  // if the packet comes from the backend port, check if this
  // is an ARP request for one of the virtual src IPs, if yes, change
  // it and send to the frontend port
  if (md->in_port == BACKEND_PORT) {
    if (arp->ar_op == bpf_htons(ARPOP_REQUEST)) {
      struct src_ip_r_key k = {32, arp->ar_tip};
      struct src_ip_r_value *v = src_ip_rewrite.lookup(&k);
      if (v && v->sense == FROM_BACKEND) {
        arp->ar_tip &= bpf_htonl(v->mask);
        arp->ar_tip |= bpf_htonl(v->net);
      }
    }
    return pcn_pkt_redirect(ctx, md, FRONTEND_PORT);
  } else if (md->in_port == FRONTEND_PORT) {
    if (arp->ar_op == bpf_htons(ARPOP_REPLY)) {
      struct src_ip_r_key k = {32, arp->ar_sip};
      struct src_ip_r_value *v = src_ip_rewrite.lookup(&k);
      if (v && v->sense == FROM_FRONTEND) {
        // send to the slowpath, it'll send to copies of this
        // - the original one
        // - one for the virtual IPs
        pcn_pkt_controller(ctx, md, 0);
        return RX_DROP;
      }
    }
    return pcn_pkt_redirect(ctx, md, BACKEND_PORT);
  } else {
    goto DROP;
  }

NOIP:
  pcn_log(ctx, LOG_TRACE, "received a non-ip packet (in_port %d) (proto 0x%x)",
          md->in_port, bpf_htons(eth->proto));

  if (md->in_port == BACKEND_PORT)
    return pcn_pkt_redirect(ctx, md, FRONTEND_PORT);
  else if (md->in_port == FRONTEND_PORT)
    return pcn_pkt_redirect(ctx, md, BACKEND_PORT);

DROP:
  pcn_log(ctx, LOG_TRACE, "DROP packet (port = %d)", md->in_port);
  return RX_DROP;
}
