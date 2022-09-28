#!/bin/bash

ips=$(kubectl get nodes -o wide | awk '{if (NR!=1) {print $6}}')

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