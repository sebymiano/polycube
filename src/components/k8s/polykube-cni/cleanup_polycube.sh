#!/bin/bash

# Kill polycubed, and wait all services to be unloaded and process to be completely killed
function polycubed_kill_and_wait {
  echo "killing polycubed ..."
  pkill polycubed > /dev/null 2>&1

  done=0
  i=0
  while : ; do
    sleep 1
    alive=$(ps -el | grep polycubed)
    if [ -z "$alive" ]; then
      done=1
    fi

    i=$((i+1))

    if [ "$done" -eq 1 ]; then
        echo "killing polycubed in $i seconds"
        break
    fi

    if [ "$i" -gt 10 ]; then
        echo "Unable to kill polycube in 10 seconds"
        break
    fi
  done
}

function remove_all_bpf_programs {
  local tmp_interfaces=$(ip -o link show | awk -F': ' '{print $2}')
  local interfaces_str="${tmp_interfaces//$'\n'/ }"

  read -a interfaces <<< "$interfaces_str"

  for if in "${interfaces[@]}"; do
    local mod_if=$(echo "${if%@*}")
    ip link set dev ${mod_if} xdp off &> /dev/null
    tc filter delete dev ${mod_if} ingress &> /dev/null
    tc filter delete dev ${mod_if} egress &> /dev/null
  done
}

function delete_additional_interfaces {
  set -x
  local tmp_interfaces=$(ip -o link show | awk -F': ' '{print $2}' | grep eth0)
  local interfaces_str="${tmp_interfaces//$'\n'/ }"

  read -a interfaces_arr <<< "$interfaces_str"

  for if in "${interfaces_arr[@]}"; do
    local mod_if=$(echo "${if%@*}")
    ip link del ${mod_if} &> /dev/null
  done
}

polycubed_kill_and_wait
remove_all_bpf_programs
ip link del dev polykube_host &> /dev/null
ip link del dev polykube_net &> /dev/null
ip link del dev vxlan0 &> /dev/null
ip link del dev pcn_xdp_cp &> /dev/null
ip link del dev pcn_tc_cp &> /dev/null
#delete_additional_interfaces

ip route restore > /ip_route
ip address restore > /ip_address
ip rule restore > /ip_rule

