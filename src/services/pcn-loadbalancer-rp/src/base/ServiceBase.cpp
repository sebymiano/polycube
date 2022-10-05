/**
* lbrp API generated from lbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "ServiceBase.h"
#include "../Lbrp.h"


ServiceBase::ServiceBase(Lbrp &parent)
    : parent_(parent) {}

ServiceBase::~ServiceBase() {}

void ServiceBase::update(const ServiceJsonObject &conf) {

  if (conf.nameIsSet()) {
    setName(conf.getName());
  }
  if (conf.backendIsSet()) {
    for (auto &i : conf.getBackend()) {
      auto ip = i.getIp();
      auto m = getBackend(ip);
      m->update(i);
    }
  }
}

ServiceJsonObject ServiceBase::toJsonObject() {
  ServiceJsonObject conf;

  conf.setName(getName());
  conf.setVip(getVip());
  conf.setVport(getVport());
  conf.setProto(getProto());
  for(auto &i : getBackendList()) {
    conf.addServiceBackend(i->toJsonObject());
  }

  return conf;
}
void ServiceBase::addBackendList(const std::vector<ServiceBackendJsonObject> &conf) {
  for (auto &i : conf) {
    std::string ip_ = i.getIp();
    addBackend(ip_, i);
  }
}

void ServiceBase::replaceBackend(const std::string &ip, const ServiceBackendJsonObject &conf) {
  delBackend(ip);
  std::string ip_ = conf.getIp();
  addBackend(ip_, conf);
}

void ServiceBase::delBackendList() {
  auto elements = getBackendList();
  for (auto &i : elements) {
    std::string ip_ = i->getIp();
    delBackend(ip_);
  }
}

std::shared_ptr<spdlog::logger> ServiceBase::logger() {
  return parent_.logger();
}
