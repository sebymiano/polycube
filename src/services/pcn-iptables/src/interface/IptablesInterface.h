/**
* iptables API
* iptables API generated from iptables.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* IptablesInterface.h
*
*
*/

#pragma once

#include "../serializer/IptablesJsonObject.h"

#include "../Chain.h"
#include "../Ports.h"
#include "../SessionTable.h"

using namespace io::swagger::server::model;

class IptablesInterface {
public:

  virtual void update(const IptablesJsonObject &conf) = 0;
  virtual IptablesJsonObject toJsonObject() = 0;

  /// <summary>
  /// Entry of the ports table
  /// </summary>
  virtual std::shared_ptr<Ports> getPorts(const std::string &name) = 0;
  virtual std::vector<std::shared_ptr<Ports>> getPortsList() = 0;
  virtual void addPorts(const std::string &name, const PortsJsonObject &conf) = 0;
  virtual void addPortsList(const std::vector<PortsJsonObject> &conf) = 0;
  virtual void replacePorts(const std::string &name, const PortsJsonObject &conf) = 0;
  virtual void delPorts(const std::string &name) = 0;
  virtual void delPortsList() = 0;

  /// <summary>
  /// Interactive mode applies new rules immediately; if &#39;false&#39;, the command &#39;apply-rules&#39; has to be used to apply all the rules at once. Default is TRUE.
  /// </summary>
  virtual bool getInteractive() = 0;
  virtual void setInteractive(const bool &value) = 0;

  /// <summary>
  /// Enables the Connection Tracking module. Mandatory if connection tracking rules are needed. Default is ON.
  /// </summary>
  virtual IptablesConntrackEnum getConntrack() = 0;
  virtual void setConntrack(const IptablesConntrackEnum &value) = 0;

  /// <summary>
  /// Enables the HORUS optimization. Default is OFF.
  /// </summary>
  virtual IptablesHorusEnum getHorus() = 0;
  virtual void setHorus(const IptablesHorusEnum &value) = 0;

  /// <summary>
  ///
  /// </summary>
  virtual std::shared_ptr<SessionTable> getSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport) = 0;
  virtual std::vector<std::shared_ptr<SessionTable>> getSessionTableList() = 0;
  virtual void addSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport, const SessionTableJsonObject &conf) = 0;
  virtual void addSessionTableList(const std::vector<SessionTableJsonObject> &conf) = 0;
  virtual void replaceSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport, const SessionTableJsonObject &conf) = 0;
  virtual void delSessionTable(const std::string &src,const std::string &dst,const std::string &l4proto,const uint16_t &sport,const uint16_t &dport) = 0;
  virtual void delSessionTableList() = 0;

  /// <summary>
  ///
  /// </summary>
  virtual std::shared_ptr<Chain> getChain(const ChainNameEnum &name) = 0;
  virtual std::vector<std::shared_ptr<Chain>> getChainList() = 0;
  virtual void addChain(const ChainNameEnum &name, const ChainJsonObject &conf) = 0;
  virtual void addChainList(const std::vector<ChainJsonObject> &conf) = 0;
  virtual void replaceChain(const ChainNameEnum &name, const ChainJsonObject &conf) = 0;
  virtual void delChain(const ChainNameEnum &name) = 0;
  virtual void delChainList() = 0;
};
