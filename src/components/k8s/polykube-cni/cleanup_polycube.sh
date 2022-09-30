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

    if [ "$i" -gt 10]; then
        echo "Unable to kill polycube in 10 seconds"
        break
    fi
  done
}

polycubed_kill_and_wait
ip link del dev polykube_host &> /dev/null
ip link del dev polykube_net &> /dev/null
ip link del dev vxlan0 &> /dev/null
ip link del dev pcn_xdp_cp &> /dev/null
ip link del dev pcn_tc_cp &> /dev/null
