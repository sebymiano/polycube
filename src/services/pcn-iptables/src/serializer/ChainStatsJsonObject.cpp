/**
* iptables API generated from iptables.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "ChainStatsJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

ChainStatsJsonObject::ChainStatsJsonObject() {
  m_idIsSet = false;
  m_pktsIsSet = false;
  m_bytesIsSet = false;
  m_descriptionIsSet = false;
}

ChainStatsJsonObject::ChainStatsJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_idIsSet = false;
  m_pktsIsSet = false;
  m_bytesIsSet = false;
  m_descriptionIsSet = false;


  if (val.count("id")) {
    setId(val.at("id").get<uint32_t>());
  }

  if (val.count("pkts")) {
    setPkts(val.at("pkts").get<uint64_t>());
  }

  if (val.count("bytes")) {
    setBytes(val.at("bytes").get<uint64_t>());
  }

  if (val.count("description")) {
    setDescription(val.at("description").get<std::string>());
  }
}

nlohmann::json ChainStatsJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_idIsSet) {
    val["id"] = m_id;
  }

  if (m_pktsIsSet) {
    val["pkts"] = m_pkts;
  }

  if (m_bytesIsSet) {
    val["bytes"] = m_bytes;
  }

  if (m_descriptionIsSet) {
    val["description"] = m_description;
  }

  return val;
}

uint32_t ChainStatsJsonObject::getId() const {
  return m_id;
}

void ChainStatsJsonObject::setId(uint32_t value) {
  m_id = value;
  m_idIsSet = true;
}

bool ChainStatsJsonObject::idIsSet() const {
  return m_idIsSet;
}



uint64_t ChainStatsJsonObject::getPkts() const {
  return m_pkts;
}

void ChainStatsJsonObject::setPkts(uint64_t value) {
  m_pkts = value;
  m_pktsIsSet = true;
}

bool ChainStatsJsonObject::pktsIsSet() const {
  return m_pktsIsSet;
}

void ChainStatsJsonObject::unsetPkts() {
  m_pktsIsSet = false;
}

uint64_t ChainStatsJsonObject::getBytes() const {
  return m_bytes;
}

void ChainStatsJsonObject::setBytes(uint64_t value) {
  m_bytes = value;
  m_bytesIsSet = true;
}

bool ChainStatsJsonObject::bytesIsSet() const {
  return m_bytesIsSet;
}

void ChainStatsJsonObject::unsetBytes() {
  m_bytesIsSet = false;
}

std::string ChainStatsJsonObject::getDescription() const {
  return m_description;
}

void ChainStatsJsonObject::setDescription(std::string value) {
  m_description = value;
  m_descriptionIsSet = true;
}

bool ChainStatsJsonObject::descriptionIsSet() const {
  return m_descriptionIsSet;
}

void ChainStatsJsonObject::unsetDescription() {
  m_descriptionIsSet = false;
}


}
}
}

