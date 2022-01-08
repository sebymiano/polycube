/**
* iptables API generated from iptables.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* ChainRuleBase.h
*
*
*/

#pragma once

#include "../serializer/ChainRuleJsonObject.h"






#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class Chain;

class ChainRuleBase {
 public:
  
  ChainRuleBase(Chain &parent);
  
  virtual ~ChainRuleBase();
  virtual void update(const ChainRuleJsonObject &conf);
  virtual ChainRuleJsonObject toJsonObject();

  /// <summary>
  /// Rule Identifier
  /// </summary>
  virtual uint32_t getId() = 0;

  /// <summary>
  /// Name of the interface via which the packet is received
  /// </summary>
  virtual std::string getInIface() = 0;
  virtual void setInIface(const std::string &value) = 0;

  /// <summary>
  /// Name of the interface via which the packet is going to be sent
  /// </summary>
  virtual std::string getOutIface() = 0;
  virtual void setOutIface(const std::string &value) = 0;

  /// <summary>
  /// Source IP Address.
  /// </summary>
  virtual std::string getSrc() = 0;
  virtual void setSrc(const std::string &value) = 0;

  /// <summary>
  /// Destination IP Address.
  /// </summary>
  virtual std::string getDst() = 0;
  virtual void setDst(const std::string &value) = 0;

  /// <summary>
  /// Level 4 Protocol.
  /// </summary>
  virtual std::string getL4proto() = 0;
  virtual void setL4proto(const std::string &value) = 0;

  /// <summary>
  /// Source L4 Port
  /// </summary>
  virtual std::string getSport() = 0;
  virtual void setSport(const std::string &value) = 0;

  /// <summary>
  /// Destination L4 Port
  /// </summary>
  virtual std::string getDport() = 0;
  virtual void setDport(const std::string &value) = 0;

  /// <summary>
  /// TCP flags. Allowed values: SYN, FIN, ACK, RST, PSH, URG, CWR, ECE. ! means set to 0.
  /// </summary>
  virtual std::string getTcpflags() = 0;
  virtual void setTcpflags(const std::string &value) = 0;

  /// <summary>
  /// Connection status (NEW, ESTABLISHED, RELATED, INVALID)
  /// </summary>
  virtual ConntrackstatusEnum getConntrack() = 0;
  virtual void setConntrack(const ConntrackstatusEnum &value) = 0;

  /// <summary>
  /// Action if the rule matches. Default is DROP.
  /// </summary>
  virtual ActionEnum getAction() = 0;
  virtual void setAction(const ActionEnum &value) = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  Chain &parent_;
};