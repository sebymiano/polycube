/**
* router API generated from router.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "ArpTableJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

ArpTableJsonObject::ArpTableJsonObject() {
  m_addressIsSet = false;
  m_macIsSet = false;
  m_interfaceIsSet = false;
}

ArpTableJsonObject::ArpTableJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_addressIsSet = false;
  m_macIsSet = false;
  m_interfaceIsSet = false;


  if (val.count("address")) {
    setAddress(val.at("address").get<std::string>());
  }

  if (val.count("mac")) {
    setMac(val.at("mac").get<std::string>());
  }

  if (val.count("interface")) {
    setInterface(val.at("interface").get<std::string>());
  }
}

nlohmann::json ArpTableJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_addressIsSet) {
    val["address"] = m_address;
  }

  if (m_macIsSet) {
    val["mac"] = m_mac;
  }

  if (m_interfaceIsSet) {
    val["interface"] = m_interface;
  }

  return val;
}

std::string ArpTableJsonObject::getAddress() const {
  return m_address;
}

void ArpTableJsonObject::setAddress(std::string value) {
  m_address = value;
  m_addressIsSet = true;
}

bool ArpTableJsonObject::addressIsSet() const {
  return m_addressIsSet;
}



std::string ArpTableJsonObject::getMac() const {
  return m_mac;
}

void ArpTableJsonObject::setMac(std::string value) {
  m_mac = value;
  m_macIsSet = true;
}

bool ArpTableJsonObject::macIsSet() const {
  return m_macIsSet;
}



std::string ArpTableJsonObject::getInterface() const {
  return m_interface;
}

void ArpTableJsonObject::setInterface(std::string value) {
  m_interface = value;
  m_interfaceIsSet = true;
}

bool ArpTableJsonObject::interfaceIsSet() const {
  return m_interfaceIsSet;
}




}
}
}

