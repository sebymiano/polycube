/**
* katran API generated from katran.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "VipJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

VipJsonObject::VipJsonObject() {
  m_addressIsSet = false;
  m_portIsSet = false;
  m_protoIsSet = false;
  m_flagsIsSet = false;
  m_realIsSet = false;
}

VipJsonObject::VipJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_addressIsSet = false;
  m_portIsSet = false;
  m_protoIsSet = false;
  m_flagsIsSet = false;
  m_realIsSet = false;


  if (val.count("address")) {
    setAddress(val.at("address").get<std::string>());
  }

  if (val.count("port")) {
    setPort(val.at("port").get<uint16_t>());
  }

  if (val.count("proto")) {
    setProto(string_to_VipProtoEnum(val.at("proto").get<std::string>()));
  }

  if (val.count("flags")) {
    setFlags(val.at("flags").get<uint32_t>());
  }

  if (val.count("real")) {
    for (auto& item : val["real"]) {
      VipRealJsonObject newItem{ item };
      m_real.push_back(newItem);
    }

    m_realIsSet = true;
  }
}

nlohmann::json VipJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_addressIsSet) {
    val["address"] = m_address;
  }

  if (m_portIsSet) {
    val["port"] = m_port;
  }

  if (m_protoIsSet) {
    val["proto"] = VipProtoEnum_to_string(m_proto);
  }

  if (m_flagsIsSet) {
    val["flags"] = m_flags;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_real) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["real"] = jsonArray;
    }
  }

  return val;
}

std::string VipJsonObject::getAddress() const {
  return m_address;
}

void VipJsonObject::setAddress(std::string value) {
  m_address = value;
  m_addressIsSet = true;
}

bool VipJsonObject::addressIsSet() const {
  return m_addressIsSet;
}



uint16_t VipJsonObject::getPort() const {
  return m_port;
}

void VipJsonObject::setPort(uint16_t value) {
  m_port = value;
  m_portIsSet = true;
}

bool VipJsonObject::portIsSet() const {
  return m_portIsSet;
}



VipProtoEnum VipJsonObject::getProto() const {
  return m_proto;
}

void VipJsonObject::setProto(VipProtoEnum value) {
  m_proto = value;
  m_protoIsSet = true;
}

bool VipJsonObject::protoIsSet() const {
  return m_protoIsSet;
}



std::string VipJsonObject::VipProtoEnum_to_string(const VipProtoEnum &value){
  switch(value) {
    case VipProtoEnum::ICMP:
      return std::string("icmp");
    case VipProtoEnum::TCP:
      return std::string("tcp");
    case VipProtoEnum::UDP:
      return std::string("udp");
    case VipProtoEnum::ALL:
      return std::string("all");
    default:
      throw std::runtime_error("Bad Vip proto");
  }
}

VipProtoEnum VipJsonObject::string_to_VipProtoEnum(const std::string &str){
  if (JsonObjectBase::iequals("icmp", str))
    return VipProtoEnum::ICMP;
  if (JsonObjectBase::iequals("tcp", str))
    return VipProtoEnum::TCP;
  if (JsonObjectBase::iequals("udp", str))
    return VipProtoEnum::UDP;
  if (JsonObjectBase::iequals("all", str))
    return VipProtoEnum::ALL;
  throw std::runtime_error("Vip proto is invalid");
}
uint32_t VipJsonObject::getFlags() const {
  return m_flags;
}

void VipJsonObject::setFlags(uint32_t value) {
  m_flags = value;
  m_flagsIsSet = true;
}

bool VipJsonObject::flagsIsSet() const {
  return m_flagsIsSet;
}

void VipJsonObject::unsetFlags() {
  m_flagsIsSet = false;
}

const std::vector<VipRealJsonObject>& VipJsonObject::getReal() const{
  return m_real;
}

void VipJsonObject::addVipReal(VipRealJsonObject value) {
  m_real.push_back(value);
  m_realIsSet = true;
}


bool VipJsonObject::realIsSet() const {
  return m_realIsSet;
}

void VipJsonObject::unsetReal() {
  m_realIsSet = false;
}


}
}
}
