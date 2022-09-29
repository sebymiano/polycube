#!/bin/bash

tmp_ips=$(kubectl get nodes -o wide | awk '{if (NR!=1) {print $6}}')
ips_str="${tmp_ips//$'\n'/ }"

read -a ips <<< "$ips_str"

# Start Morpheus on intLbrp
for ip in "${ips[@]}"; do
    POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl ilb0 set start-morpheus=true
done

# Start Morpheus on router
for ip in "${ips[@]}"; do
    POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl r0 set start-morpheus=true
done

# Start Morpheus on extLbrp
for ip in "${ips[@]}"; do
    POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl elb0 set start-morpheus=true
done

# Start Morpheus on k8sdispatcher
for ip in "${ips[@]}"; do
    POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl k0 set start-morpheus=true
done