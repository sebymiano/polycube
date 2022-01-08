/**
* iptables API generated from iptables.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "ChainRuleBase.h"
#include "../Iptables.h"


ChainRuleBase::ChainRuleBase(Chain &parent)
    : parent_(parent) {}

ChainRuleBase::~ChainRuleBase() {}

void ChainRuleBase::update(const ChainRuleJsonObject &conf) {

  if (conf.inIfaceIsSet()) {
    setInIface(conf.getInIface());
  }
  if (conf.outIfaceIsSet()) {
    setOutIface(conf.getOutIface());
  }
  if (conf.srcIsSet()) {
    setSrc(conf.getSrc());
  }
  if (conf.dstIsSet()) {
    setDst(conf.getDst());
  }
  if (conf.l4protoIsSet()) {
    setL4proto(conf.getL4proto());
  }
  if (conf.sportIsSet()) {
    setSport(conf.getSport());
  }
  if (conf.dportIsSet()) {
    setDport(conf.getDport());
  }
  if (conf.tcpflagsIsSet()) {
    setTcpflags(conf.getTcpflags());
  }
  if (conf.conntrackIsSet()) {
    setConntrack(conf.getConntrack());
  }
  if (conf.actionIsSet()) {
    setAction(conf.getAction());
  }
}

ChainRuleJsonObject ChainRuleBase::toJsonObject() {
  ChainRuleJsonObject conf;

  conf.setId(getId());
  conf.setInIface(getInIface());
  conf.setOutIface(getOutIface());
  conf.setSrc(getSrc());
  conf.setDst(getDst());
  conf.setL4proto(getL4proto());
  conf.setSport(getSport());
  conf.setDport(getDport());
  conf.setTcpflags(getTcpflags());
  conf.setConntrack(getConntrack());
  conf.setAction(getAction());

  return conf;
}

std::shared_ptr<spdlog::logger> ChainRuleBase::logger() {
  return parent_.logger();
}
