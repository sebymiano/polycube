/**
* bmc API generated from bmc.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "BmcStatsResetAllOutputJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

BmcStatsResetAllOutputJsonObject::BmcStatsResetAllOutputJsonObject() {
  m_resultIsSet = false;
}

BmcStatsResetAllOutputJsonObject::BmcStatsResetAllOutputJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_resultIsSet = false;


  if (val.count("result")) {
    setResult(val.at("result").get<bool>());
  }
}

nlohmann::json BmcStatsResetAllOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_resultIsSet) {
    val["result"] = m_result;
  }

  return val;
}

bool BmcStatsResetAllOutputJsonObject::getResult() const {
  return m_result;
}

void BmcStatsResetAllOutputJsonObject::setResult(bool value) {
  m_result = value;
  m_resultIsSet = true;
}

bool BmcStatsResetAllOutputJsonObject::resultIsSet() const {
  return m_resultIsSet;
}

void BmcStatsResetAllOutputJsonObject::unsetResult() {
  m_resultIsSet = false;
}


}
}
}

