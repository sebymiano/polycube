#!/bin/bash

COLOR_RED='\033[0;31m'
COLOR_GREEN='\033[0;32m'
COLOR_YELLOW='\033[0;33m'
COLOR_OFF='\033[0m' # No Color

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo -e "${COLOR_YELLOW}[ INFO ] Make sure you have installed all Polycube dependencies first ${COLOR_OFF}"

[ -z ${SUDO+x} ] && SUDO='sudo'

$SUDO apt update

install_kubeadm() {
  echo -e "${COLOR_GREE}[ INFO ] Installing Kubeadm ${COLOR_OFF}"
  $SUDO apt install -y apt-transport-https ca-certificates curl
  $SUDO curl -fsSLo /usr/share/keyrings/kubernetes-archive-keyring.gpg https://packages.cloud.google.com/apt/doc/apt-key.gpg
  echo "deb [signed-by=/usr/share/keyrings/kubernetes-archive-keyring.gpg] https://apt.kubernetes.io/ kubernetes-xenial main" | $SUDO tee /etc/apt/sources.list.d/kubernetes.list
  $SUDO apt update
  $SUDO apt install -y kubelet kubeadm kubectl
  $SUDO apt-mark hold kubelet kubeadm kubectl
}

install_docker() {
    echo -e "${COLOR_GREE}[ INFO ] Installing Docker runtime ${COLOR_OFF}"
    $SUDO apt remove -y docker docker-engine docker.io containerd runc
    $SUDO apt update
    $SUDO apt install -y ca-certificates curl gnupg lsb-release

    $SUDO mkdir -p /etc/apt/keyrings
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | $SUDO gpg --dearmor -o /etc/apt/keyrings/docker.gpg
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
    $SUDO apt update
    $SUDO apt install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin
    $SUDO service docker start
    $SUDO rm /etc/containerd/config.toml
    $SUDO systemctl restart containerd
}

kubeadm init

install_kubeadm
install_docker

$SUDO swapoff -a

echo -e "${COLOR_GREE}[ INFO ] Installation completed, now you can run your k8s cluster ${COLOR_OFF}"