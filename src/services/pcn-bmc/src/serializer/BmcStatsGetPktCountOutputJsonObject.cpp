/**
* bmc API generated from bmc.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "BmcStatsGetPktCountOutputJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

BmcStatsGetPktCountOutputJsonObject::BmcStatsGetPktCountOutputJsonObject() {
  m_averageIsSet = false;
}

BmcStatsGetPktCountOutputJsonObject::BmcStatsGetPktCountOutputJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_averageIsSet = false;


  if (val.count("average")) {
    setAverage(val.at("average").get<uint64_t>());
  }
}

nlohmann::json BmcStatsGetPktCountOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_averageIsSet) {
    val["average"] = m_average;
  }

  return val;
}

uint64_t BmcStatsGetPktCountOutputJsonObject::getAverage() const {
  return m_average;
}

void BmcStatsGetPktCountOutputJsonObject::setAverage(uint64_t value) {
  m_average = value;
  m_averageIsSet = true;
}

bool BmcStatsGetPktCountOutputJsonObject::averageIsSet() const {
  return m_averageIsSet;
}

void BmcStatsGetPktCountOutputJsonObject::unsetAverage() {
  m_averageIsSet = false;
}


}
}
}

