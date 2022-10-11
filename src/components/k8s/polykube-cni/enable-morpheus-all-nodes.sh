#!/bin/bash

tmp_ips=$(kubectl get nodes -o wide | grep -v 'control-plane' | awk '{if (NR!=1) {print $6}}')
ips_str="${tmp_ips//$'\n'/ }"

read -a ips <<< "$ips_str"

ENABLE_ROUTER="true"
ENABLE_LBRP="true"
ENABLE_K8S_DISPATCHER="true"

function show_help() {
usage="$(basename "$0") -r -l -k
Morpheus-k8s start script

mode:
  -r: disable Morpheus on router service
  -l: disable Morpheus on load balancer service
  -k: disable Morpheus on k8s dispatcher service"
echo "$usage"
echo
}

while getopts rlkh option; do
 case "${option}" in
 h|\?)
  show_help
  exit 0
  ;;
 r) ENABLE_ROUTER="false"
	;;
 l) ENABLE_LBRP="false"
	;;
 k) ENABLE_K8S_DISPATCHER="false"
	;;
 :)
  echo "Option -$OPTARG requires an argument." >&2
  show_help
  exit 0
  ;;
 esac
done

if [ $ENABLE_LBRP == "true" ]; then
    # Start Morpheus on intLbrp
    for ip in "${ips[@]}"; do
        POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl ilb0 set start-morpheus=true
    done
fi

if [ $ENABLE_ROUTER == "true" ]; then
    # Start Morpheus on router
    for ip in "${ips[@]}"; do
        POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl r0 set start-morpheus=true
    done
fi 

if [ $ENABLE_LBRP == "true" ]; then
    # Start Morpheus on extLbrp
    for ip in "${ips[@]}"; do
        POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl elb0 set start-morpheus=true
    done
fi

if [ $ENABLE_K8S_DISPATCHER == "true" ]; then
    # Start Morpheus on k8sdispatcher
    for ip in "${ips[@]}"; do
        POLYCUBECTL_URL=http://${ip}:9000/polycube/v1/ polycubectl k0 set start-morpheus=true
    done
fi