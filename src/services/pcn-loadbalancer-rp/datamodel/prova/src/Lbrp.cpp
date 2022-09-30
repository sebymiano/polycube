/**
* lbrp API generated from lbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


// TODO: Modify these methods with your own implementation


#include "Lbrp.h"
#include "Lbrp_dp.h"

Lbrp::Lbrp(const std::string name, const LbrpJsonObject &conf)
  : Cube(conf.getBase(), { lbrp_code }, {}),
    LbrpBase(name) {
  logger()->info("Creating Lbrp instance");
    setStartMorpheus(conf.getStartMorpheus());
  addPortsList(conf.getPorts());
    setPortMode(conf.getPortMode());
  addSrcIpRewrite(conf.getSrcIpRewrite());
  addServiceList(conf.getService());
}


Lbrp::~Lbrp() {
  logger()->info("Destroying Lbrp instance");
}

void Lbrp::packet_in(Ports &port,
    polycube::service::PacketInMetadata &md,
    const std::vector<uint8_t> &packet) {
  logger()->debug("Packet received from port {0}", port.name());
}

bool Lbrp::getDynOpt() {
  throw std::runtime_error("Lbrp::getDynOpt: Method not implemented");
}

bool Lbrp::getStartMorpheus() {
  throw std::runtime_error("Lbrp::getStartMorpheus: Method not implemented");
}

void Lbrp::setStartMorpheus(const bool &value) {
  throw std::runtime_error("Lbrp::setStartMorpheus: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
std::shared_ptr<Ports> Lbrp::getPorts(const std::string &name) {
  // call default implementation in base class
  return LbrpBase::getPorts(name);
}

// Basic default implementation, place your extension here (if needed)
std::vector<std::shared_ptr<Ports>> Lbrp::getPortsList() {
  // call default implementation in base class
  return LbrpBase::getPortsList();
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::addPorts(const std::string &name, const PortsJsonObject &conf) {
  LbrpBase::addPorts(name, conf);
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::addPortsList(const std::vector<PortsJsonObject> &conf) {
  // call default implementation in base class
  LbrpBase::addPortsList(conf);
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::replacePorts(const std::string &name, const PortsJsonObject &conf) {
  // call default implementation in base class
  LbrpBase::replacePorts(name, conf);
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::delPorts(const std::string &name) {
  // call default implementation in base class
  LbrpBase::delPorts(name);
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::delPortsList() {
  // call default implementation in base class
  LbrpBase::delPortsList();
}

LbrpPortModeEnum Lbrp::getPortMode() {
  throw std::runtime_error("Lbrp::getPortMode: Method not implemented");
}

void Lbrp::setPortMode(const LbrpPortModeEnum &value) {
  throw std::runtime_error("Lbrp::setPortMode: Method not implemented");
}

std::shared_ptr<SrcIpRewrite> Lbrp::getSrcIpRewrite() {
  throw std::runtime_error("Lbrp::getSrcIpRewrite: Method not implemented");
}

void Lbrp::addSrcIpRewrite(const SrcIpRewriteJsonObject &value) {
  throw std::runtime_error("Lbrp::addSrcIpRewrite: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::replaceSrcIpRewrite(const SrcIpRewriteJsonObject &conf) {
  // call default implementation in base class
  LbrpBase::replaceSrcIpRewrite(conf);
}

void Lbrp::delSrcIpRewrite() {
  throw std::runtime_error("Lbrp::delSrcIpRewrite: method not implemented");
}
std::shared_ptr<Service> Lbrp::getService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  throw std::runtime_error("Lbrp::getEntry: Method not implemented");
}

std::vector<std::shared_ptr<Service>> Lbrp::getServiceList() {
  throw std::runtime_error("Lbrp::getServiceList: Method not implemented");
}

void Lbrp::addService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &conf) {
  throw std::runtime_error("Lbrp::addService: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::addServiceList(const std::vector<ServiceJsonObject> &conf) {
  // call default implementation in base class
  LbrpBase::addServiceList(conf);
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::replaceService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &conf) {
  // call default implementation in base class
  LbrpBase::replaceService(vip, vport, proto, conf);
}

void Lbrp::delService(const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  throw std::runtime_error("Lbrp::delService: Method not implemented");
}

// Basic default implementation, place your extension here (if needed)
void Lbrp::delServiceList() {
  // call default implementation in base class
  LbrpBase::delServiceList();
}


