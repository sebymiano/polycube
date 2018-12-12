/**
* router API
* Router Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "RouteJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

RouteJsonObject::RouteJsonObject() {

  m_networkIsSet = false;

  m_netmaskIsSet = false;

  m_nexthopIsSet = false;

  m_interfaceIsSet = false;

  m_pathcost = 1;
  m_pathcostIsSet = false;
}

RouteJsonObject::~RouteJsonObject() {}

void RouteJsonObject::validateKeys() {

  if (!m_networkIsSet) {
    throw std::runtime_error("Variable network is required");
  }
  if (!m_netmaskIsSet) {
    throw std::runtime_error("Variable netmask is required");
  }
  if (!m_nexthopIsSet) {
    throw std::runtime_error("Variable nexthop is required");
  }
}

void RouteJsonObject::validateMandatoryFields() {

}

void RouteJsonObject::validateParams() {

  if (m_networkIsSet) {
    std::string patter_value = R"PATTERN((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(%[\p{N}\p{L}]+)?)PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_network, e))
      throw std::runtime_error("Variable network has not a valid format");
  }
  if (m_netmaskIsSet) {
    std::string patter_value = R"PATTERN((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(%[\p{N}\p{L}]+)?)PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_netmask, e))
      throw std::runtime_error("Variable netmask has not a valid format");
  }
  if (m_nexthopIsSet) {
    std::string patter_value = R"PATTERN((([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(%[\p{N}\p{L}]+)?)PATTERN";
    std::regex e (patter_value);
    if (!std::regex_match(m_nexthop, e))
      throw std::runtime_error("Variable nexthop has not a valid format");
  }
}

nlohmann::json RouteJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_networkIsSet) {
    val["network"] = m_network;
  }

  if (m_netmaskIsSet) {
    val["netmask"] = m_netmask;
  }

  if (m_nexthopIsSet) {
    val["nexthop"] = m_nexthop;
  }

  if (m_interfaceIsSet) {
    val["interface"] = m_interface;
  }

  if (m_pathcostIsSet) {
    val["pathcost"] = m_pathcost;
  }


  return val;
}

void RouteJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("network") != val.end()) {
    setNetwork(val.at("network"));
  }

  if (val.find("netmask") != val.end()) {
    setNetmask(val.at("netmask"));
  }

  if (val.find("nexthop") != val.end()) {
    setNexthop(val.at("nexthop"));
  }

  if (val.find("interface") != val.end()) {
    setInterface(val.at("interface"));
  }

  if (val.find("pathcost") != val.end()) {
    setPathcost(val.at("pathcost"));
  }
}

nlohmann::json RouteJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["network"]["name"] = "network";
  val["network"]["type"] = "key";
  val["network"]["simpletype"] = "string";
  val["network"]["description"] = R"POLYCUBE(Destination network IP)POLYCUBE";
  val["network"]["example"] = R"POLYCUBE(123.13.34.0)POLYCUBE";
  val["netmask"]["name"] = "netmask";
  val["netmask"]["type"] = "key";
  val["netmask"]["simpletype"] = "string";
  val["netmask"]["description"] = R"POLYCUBE(Destination network netmask)POLYCUBE";
  val["netmask"]["example"] = R"POLYCUBE(255.255.255.0)POLYCUBE";
  val["nexthop"]["name"] = "nexthop";
  val["nexthop"]["type"] = "key";
  val["nexthop"]["simpletype"] = "string";
  val["nexthop"]["description"] = R"POLYCUBE(Next hop; if destination is local will be shown 'local' instead of the ip address)POLYCUBE";
  val["nexthop"]["example"] = R"POLYCUBE(123.14.23.3)POLYCUBE";

  return val;
}

nlohmann::json RouteJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["interface"]["name"] = "interface";
  val["interface"]["type"] = "leaf"; // Suppose that type is leaf
  val["interface"]["simpletype"] = "string";
  val["interface"]["description"] = R"POLYCUBE(Outgoing interface)POLYCUBE";
  val["interface"]["example"] = R"POLYCUBE(port2)POLYCUBE";
  val["pathcost"]["name"] = "pathcost";
  val["pathcost"]["type"] = "leaf"; // Suppose that type is leaf
  val["pathcost"]["simpletype"] = "integer";
  val["pathcost"]["description"] = R"POLYCUBE(Cost of this route)POLYCUBE";
  val["pathcost"]["example"] = R"POLYCUBE(10)POLYCUBE";

  return val;
}

nlohmann::json RouteJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["pathcost"]["name"] = "pathcost";
  val["pathcost"]["simpletype"] = "integer";
  val["pathcost"]["description"] = R"POLYCUBE(Cost of this route)POLYCUBE";
  val["pathcost"]["example"] = R"POLYCUBE(10)POLYCUBE";

  return val;
}

nlohmann::json RouteJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> RouteJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string RouteJsonObject::getNetwork() const {
  return m_network;
}

void RouteJsonObject::setNetwork(std::string value) {
  m_network = value;
  m_networkIsSet = true;
}

bool RouteJsonObject::networkIsSet() const {
  return m_networkIsSet;
}

void RouteJsonObject::unsetNetwork() {
  m_networkIsSet = false;
}



std::string RouteJsonObject::getNetmask() const {
  return m_netmask;
}

void RouteJsonObject::setNetmask(std::string value) {
  m_netmask = value;
  m_netmaskIsSet = true;
}

bool RouteJsonObject::netmaskIsSet() const {
  return m_netmaskIsSet;
}

void RouteJsonObject::unsetNetmask() {
  m_netmaskIsSet = false;
}



std::string RouteJsonObject::getNexthop() const {
  return m_nexthop;
}

void RouteJsonObject::setNexthop(std::string value) {
  m_nexthop = value;
  m_nexthopIsSet = true;
}

bool RouteJsonObject::nexthopIsSet() const {
  return m_nexthopIsSet;
}

void RouteJsonObject::unsetNexthop() {
  m_nexthopIsSet = false;
}



std::string RouteJsonObject::getInterface() const {
  return m_interface;
}

void RouteJsonObject::setInterface(std::string value) {
  m_interface = value;
  m_interfaceIsSet = true;
}

bool RouteJsonObject::interfaceIsSet() const {
  return m_interfaceIsSet;
}

void RouteJsonObject::unsetInterface() {
  m_interfaceIsSet = false;
}



int32_t RouteJsonObject::getPathcost() const {
  return m_pathcost;
}

void RouteJsonObject::setPathcost(int32_t value) {
  m_pathcost = value;
  m_pathcostIsSet = true;
}

bool RouteJsonObject::pathcostIsSet() const {
  return m_pathcostIsSet;
}

void RouteJsonObject::unsetPathcost() {
  m_pathcostIsSet = false;
}




}
}
}
}
