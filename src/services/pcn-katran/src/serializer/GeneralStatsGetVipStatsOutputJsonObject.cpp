/**
* katran API generated from katran.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "GeneralStatsGetVipStatsOutputJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

GeneralStatsGetVipStatsOutputJsonObject::GeneralStatsGetVipStatsOutputJsonObject() {
  m_v1IsSet = false;
  m_v2IsSet = false;
}

GeneralStatsGetVipStatsOutputJsonObject::GeneralStatsGetVipStatsOutputJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_v1IsSet = false;
  m_v2IsSet = false;


  if (val.count("v1")) {
    setV1(val.at("v1").get<uint64_t>());
  }

  if (val.count("v2")) {
    setV2(val.at("v2").get<uint64_t>());
  }
}

nlohmann::json GeneralStatsGetVipStatsOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_v1IsSet) {
    val["v1"] = m_v1;
  }

  if (m_v2IsSet) {
    val["v2"] = m_v2;
  }

  return val;
}

uint64_t GeneralStatsGetVipStatsOutputJsonObject::getV1() const {
  return m_v1;
}

void GeneralStatsGetVipStatsOutputJsonObject::setV1(uint64_t value) {
  m_v1 = value;
  m_v1IsSet = true;
}

bool GeneralStatsGetVipStatsOutputJsonObject::v1IsSet() const {
  return m_v1IsSet;
}

void GeneralStatsGetVipStatsOutputJsonObject::unsetV1() {
  m_v1IsSet = false;
}

uint64_t GeneralStatsGetVipStatsOutputJsonObject::getV2() const {
  return m_v2;
}

void GeneralStatsGetVipStatsOutputJsonObject::setV2(uint64_t value) {
  m_v2 = value;
  m_v2IsSet = true;
}

bool GeneralStatsGetVipStatsOutputJsonObject::v2IsSet() const {
  return m_v2IsSet;
}

void GeneralStatsGetVipStatsOutputJsonObject::unsetV2() {
  m_v2IsSet = false;
}


}
}
}

