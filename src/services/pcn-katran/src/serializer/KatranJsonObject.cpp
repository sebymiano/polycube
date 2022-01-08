/**
* katran API generated from katran.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "KatranJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

KatranJsonObject::KatranJsonObject() {
  m_nameIsSet = false;
  m_dynOpt = false;
  m_dynOptIsSet = true;
  m_portsIsSet = false;
  m_generalStatsIsSet = false;
  m_defaultMacIsSet = false;
  m_enableHc = true;
  m_enableHcIsSet = true;
  m_maxVipsIsSet = false;
  m_maxRealsIsSet = false;
  m_chRingSizeIsSet = false;
  m_forwardingCores = "0";
  m_forwardingCoresIsSet = true;
  m_numaNodesIsSet = false;
  m_lruSizeIsSet = false;
  m_vipIsSet = false;
}

KatranJsonObject::KatranJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_nameIsSet = false;
  m_dynOptIsSet = false;
  m_portsIsSet = false;
  m_generalStatsIsSet = false;
  m_defaultMacIsSet = false;
  m_enableHcIsSet = false;
  m_maxVipsIsSet = false;
  m_maxRealsIsSet = false;
  m_chRingSizeIsSet = false;
  m_forwardingCoresIsSet = false;
  m_numaNodesIsSet = false;
  m_lruSizeIsSet = false;
  m_vipIsSet = false;


  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }

  if (val.count("dyn-opt")) {
    setDynOpt(val.at("dyn-opt").get<bool>());
  }

  if (val.count("ports")) {
    for (auto& item : val["ports"]) {
      PortsJsonObject newItem{ item };
      m_ports.push_back(newItem);
    }

    m_portsIsSet = true;
  }

  if (val.count("generalStats")) {
    if (!val["generalStats"].is_null()) {
      GeneralStatsJsonObject newItem { val["generalStats"] };
      setGeneralStats(newItem);
    }
  }

  if (val.count("defaultMac")) {
    setDefaultMac(val.at("defaultMac").get<std::string>());
  }

  if (val.count("enableHc")) {
    setEnableHc(val.at("enableHc").get<bool>());
  }

  if (val.count("maxVips")) {
    setMaxVips(val.at("maxVips").get<uint32_t>());
  }

  if (val.count("maxReals")) {
    setMaxReals(val.at("maxReals").get<uint32_t>());
  }

  if (val.count("chRingSize")) {
    setChRingSize(val.at("chRingSize").get<uint32_t>());
  }

  if (val.count("forwardingCores")) {
    setForwardingCores(val.at("forwardingCores").get<std::string>());
  }

  if (val.count("numaNodes")) {
    setNumaNodes(val.at("numaNodes").get<std::string>());
  }

  if (val.count("lruSize")) {
    setLruSize(val.at("lruSize").get<uint64_t>());
  }

  if (val.count("vip")) {
    for (auto& item : val["vip"]) {
      VipJsonObject newItem{ item };
      m_vip.push_back(newItem);
    }

    m_vipIsSet = true;
  }
}

nlohmann::json KatranJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  if (m_dynOptIsSet) {
    val["dyn-opt"] = m_dynOpt;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_ports) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["ports"] = jsonArray;
    }
  }

  if (m_generalStatsIsSet) {
    val["generalStats"] = JsonObjectBase::toJson(m_generalStats);
  }

  if (m_defaultMacIsSet) {
    val["defaultMac"] = m_defaultMac;
  }

  if (m_enableHcIsSet) {
    val["enableHc"] = m_enableHc;
  }

  if (m_maxVipsIsSet) {
    val["maxVips"] = m_maxVips;
  }

  if (m_maxRealsIsSet) {
    val["maxReals"] = m_maxReals;
  }

  if (m_chRingSizeIsSet) {
    val["chRingSize"] = m_chRingSize;
  }

  if (m_forwardingCoresIsSet) {
    val["forwardingCores"] = m_forwardingCores;
  }

  if (m_numaNodesIsSet) {
    val["numaNodes"] = m_numaNodes;
  }

  if (m_lruSizeIsSet) {
    val["lruSize"] = m_lruSize;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_vip) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["vip"] = jsonArray;
    }
  }

  return val;
}

std::string KatranJsonObject::getName() const {
  return m_name;
}

void KatranJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool KatranJsonObject::nameIsSet() const {
  return m_nameIsSet;
}



bool KatranJsonObject::getDynOpt() const {
  return m_dynOpt;
}

void KatranJsonObject::setDynOpt(bool value) {
  m_dynOpt = value;
  m_dynOptIsSet = true;
}

bool KatranJsonObject::dynOptIsSet() const {
  return m_dynOptIsSet;
}

void KatranJsonObject::unsetDynOpt() {
  m_dynOptIsSet = false;
}

const std::vector<PortsJsonObject>& KatranJsonObject::getPorts() const{
  return m_ports;
}

void KatranJsonObject::addPorts(PortsJsonObject value) {
  m_ports.push_back(value);
  m_portsIsSet = true;
}


bool KatranJsonObject::portsIsSet() const {
  return m_portsIsSet;
}

void KatranJsonObject::unsetPorts() {
  m_portsIsSet = false;
}

GeneralStatsJsonObject KatranJsonObject::getGeneralStats() const {
  return m_generalStats;
}

void KatranJsonObject::setGeneralStats(GeneralStatsJsonObject value) {
  m_generalStats = value;
  m_generalStatsIsSet = true;
}

bool KatranJsonObject::generalStatsIsSet() const {
  return m_generalStatsIsSet;
}

void KatranJsonObject::unsetGeneralStats() {
  m_generalStatsIsSet = false;
}

std::string KatranJsonObject::getDefaultMac() const {
  return m_defaultMac;
}

void KatranJsonObject::setDefaultMac(std::string value) {
  m_defaultMac = value;
  m_defaultMacIsSet = true;
}

bool KatranJsonObject::defaultMacIsSet() const {
  return m_defaultMacIsSet;
}



bool KatranJsonObject::getEnableHc() const {
  return m_enableHc;
}

void KatranJsonObject::setEnableHc(bool value) {
  m_enableHc = value;
  m_enableHcIsSet = true;
}

bool KatranJsonObject::enableHcIsSet() const {
  return m_enableHcIsSet;
}

void KatranJsonObject::unsetEnableHc() {
  m_enableHcIsSet = false;
}

uint32_t KatranJsonObject::getMaxVips() const {
  return m_maxVips;
}

void KatranJsonObject::setMaxVips(uint32_t value) {
  m_maxVips = value;
  m_maxVipsIsSet = true;
}

bool KatranJsonObject::maxVipsIsSet() const {
  return m_maxVipsIsSet;
}

void KatranJsonObject::unsetMaxVips() {
  m_maxVipsIsSet = false;
}

uint32_t KatranJsonObject::getMaxReals() const {
  return m_maxReals;
}

void KatranJsonObject::setMaxReals(uint32_t value) {
  m_maxReals = value;
  m_maxRealsIsSet = true;
}

bool KatranJsonObject::maxRealsIsSet() const {
  return m_maxRealsIsSet;
}

void KatranJsonObject::unsetMaxReals() {
  m_maxRealsIsSet = false;
}

uint32_t KatranJsonObject::getChRingSize() const {
  return m_chRingSize;
}

void KatranJsonObject::setChRingSize(uint32_t value) {
  m_chRingSize = value;
  m_chRingSizeIsSet = true;
}

bool KatranJsonObject::chRingSizeIsSet() const {
  return m_chRingSizeIsSet;
}

void KatranJsonObject::unsetChRingSize() {
  m_chRingSizeIsSet = false;
}

std::string KatranJsonObject::getForwardingCores() const {
  return m_forwardingCores;
}

void KatranJsonObject::setForwardingCores(std::string value) {
  m_forwardingCores = value;
  m_forwardingCoresIsSet = true;
}

bool KatranJsonObject::forwardingCoresIsSet() const {
  return m_forwardingCoresIsSet;
}

void KatranJsonObject::unsetForwardingCores() {
  m_forwardingCoresIsSet = false;
}

std::string KatranJsonObject::getNumaNodes() const {
  return m_numaNodes;
}

void KatranJsonObject::setNumaNodes(std::string value) {
  m_numaNodes = value;
  m_numaNodesIsSet = true;
}

bool KatranJsonObject::numaNodesIsSet() const {
  return m_numaNodesIsSet;
}

void KatranJsonObject::unsetNumaNodes() {
  m_numaNodesIsSet = false;
}

uint64_t KatranJsonObject::getLruSize() const {
  return m_lruSize;
}

void KatranJsonObject::setLruSize(uint64_t value) {
  m_lruSize = value;
  m_lruSizeIsSet = true;
}

bool KatranJsonObject::lruSizeIsSet() const {
  return m_lruSizeIsSet;
}

void KatranJsonObject::unsetLruSize() {
  m_lruSizeIsSet = false;
}

const std::vector<VipJsonObject>& KatranJsonObject::getVip() const{
  return m_vip;
}

void KatranJsonObject::addVip(VipJsonObject value) {
  m_vip.push_back(value);
  m_vipIsSet = true;
}


bool KatranJsonObject::vipIsSet() const {
  return m_vipIsSet;
}

void KatranJsonObject::unsetVip() {
  m_vipIsSet = false;
}


}
}
}
