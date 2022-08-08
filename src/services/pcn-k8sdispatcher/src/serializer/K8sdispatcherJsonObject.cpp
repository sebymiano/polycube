/**
* k8sdispatcher API generated from k8sdispatcher.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "K8sdispatcherJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

K8sdispatcherJsonObject::K8sdispatcherJsonObject() {
  m_nameIsSet = false;
  m_portsIsSet = false;
  m_internalSrcIpIsSet = false;
  m_nodeportRange = "30000-32767";
  m_nodeportRangeIsSet = true;
  m_sessionRuleIsSet = false;
  m_nodeportRuleIsSet = false;
}

K8sdispatcherJsonObject::K8sdispatcherJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_nameIsSet = false;
  m_portsIsSet = false;
  m_internalSrcIpIsSet = false;
  m_nodeportRangeIsSet = false;
  m_sessionRuleIsSet = false;
  m_nodeportRuleIsSet = false;


  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }

  if (val.count("ports")) {
    for (auto& item : val["ports"]) {
      PortsJsonObject newItem{ item };
      m_ports.push_back(newItem);
    }

    m_portsIsSet = true;
  }

  if (val.count("internal-src-ip")) {
    setInternalSrcIp(val.at("internal-src-ip").get<std::string>());
  }

  if (val.count("nodeport-range")) {
    setNodeportRange(val.at("nodeport-range").get<std::string>());
  }

  if (val.count("session-rule")) {
    for (auto& item : val["session-rule"]) {
      SessionRuleJsonObject newItem{ item };
      m_sessionRule.push_back(newItem);
    }

    m_sessionRuleIsSet = true;
  }

  if (val.count("nodeport-rule")) {
    for (auto& item : val["nodeport-rule"]) {
      NodeportRuleJsonObject newItem{ item };
      m_nodeportRule.push_back(newItem);
    }

    m_nodeportRuleIsSet = true;
  }
}

nlohmann::json K8sdispatcherJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_nameIsSet) {
    val["name"] = m_name;
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

  if (m_internalSrcIpIsSet) {
    val["internal-src-ip"] = m_internalSrcIp;
  }

  if (m_nodeportRangeIsSet) {
    val["nodeport-range"] = m_nodeportRange;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_sessionRule) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["session-rule"] = jsonArray;
    }
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_nodeportRule) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }

    if (jsonArray.size() > 0) {
      val["nodeport-rule"] = jsonArray;
    }
  }

  return val;
}

std::string K8sdispatcherJsonObject::getName() const {
  return m_name;
}

void K8sdispatcherJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool K8sdispatcherJsonObject::nameIsSet() const {
  return m_nameIsSet;
}



const std::vector<PortsJsonObject>& K8sdispatcherJsonObject::getPorts() const{
  return m_ports;
}

void K8sdispatcherJsonObject::addPorts(PortsJsonObject value) {
  m_ports.push_back(value);
  m_portsIsSet = true;
}


bool K8sdispatcherJsonObject::portsIsSet() const {
  return m_portsIsSet;
}

void K8sdispatcherJsonObject::unsetPorts() {
  m_portsIsSet = false;
}

std::string K8sdispatcherJsonObject::getInternalSrcIp() const {
  return m_internalSrcIp;
}

void K8sdispatcherJsonObject::setInternalSrcIp(std::string value) {
  m_internalSrcIp = value;
  m_internalSrcIpIsSet = true;
}

bool K8sdispatcherJsonObject::internalSrcIpIsSet() const {
  return m_internalSrcIpIsSet;
}



std::string K8sdispatcherJsonObject::getNodeportRange() const {
  return m_nodeportRange;
}

void K8sdispatcherJsonObject::setNodeportRange(std::string value) {
  m_nodeportRange = value;
  m_nodeportRangeIsSet = true;
}

bool K8sdispatcherJsonObject::nodeportRangeIsSet() const {
  return m_nodeportRangeIsSet;
}

void K8sdispatcherJsonObject::unsetNodeportRange() {
  m_nodeportRangeIsSet = false;
}

const std::vector<SessionRuleJsonObject>& K8sdispatcherJsonObject::getSessionRule() const{
  return m_sessionRule;
}

void K8sdispatcherJsonObject::addSessionRule(SessionRuleJsonObject value) {
  m_sessionRule.push_back(value);
  m_sessionRuleIsSet = true;
}


bool K8sdispatcherJsonObject::sessionRuleIsSet() const {
  return m_sessionRuleIsSet;
}

void K8sdispatcherJsonObject::unsetSessionRule() {
  m_sessionRuleIsSet = false;
}

const std::vector<NodeportRuleJsonObject>& K8sdispatcherJsonObject::getNodeportRule() const{
  return m_nodeportRule;
}

void K8sdispatcherJsonObject::addNodeportRule(NodeportRuleJsonObject value) {
  m_nodeportRule.push_back(value);
  m_nodeportRuleIsSet = true;
}


bool K8sdispatcherJsonObject::nodeportRuleIsSet() const {
  return m_nodeportRuleIsSet;
}

void K8sdispatcherJsonObject::unsetNodeportRule() {
  m_nodeportRuleIsSet = false;
}


}
}
}
