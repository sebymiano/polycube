/**
* lbrp API generated from lbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "SrcIpRewriteBase.h"
#include "../Lbrp.h"


SrcIpRewriteBase::SrcIpRewriteBase(Lbrp &parent)
    : parent_(parent) {}

SrcIpRewriteBase::~SrcIpRewriteBase() {}

void SrcIpRewriteBase::update(const SrcIpRewriteJsonObject &conf) {

  if (conf.ipRangeIsSet()) {
    setIpRange(conf.getIpRange());
  }
  if (conf.newIpRangeIsSet()) {
    setNewIpRange(conf.getNewIpRange());
  }
}

SrcIpRewriteJsonObject SrcIpRewriteBase::toJsonObject() {
  SrcIpRewriteJsonObject conf;

  conf.setIpRange(getIpRange());
  conf.setNewIpRange(getNewIpRange());

  return conf;
}

std::shared_ptr<spdlog::logger> SrcIpRewriteBase::logger() {
  return parent_.logger();
}
