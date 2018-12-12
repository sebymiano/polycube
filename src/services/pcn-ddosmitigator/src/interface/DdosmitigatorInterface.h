/**
* ddosmitigator API
* DDoS Mitigator Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* DdosmitigatorInterface.h
*
*
*/

#pragma once

#include "../serializer/DdosmitigatorJsonObject.h"

#include "../BlacklistDst.h"
#include "../BlacklistSrc.h"
#include "../Ports.h"
#include "../Stats.h"

using namespace io::swagger::server::model;

class DdosmitigatorInterface {
public:

  virtual void update(const DdosmitigatorJsonObject &conf) = 0;
  virtual DdosmitigatorJsonObject toJsonObject() = 0;

  /// <summary>
  /// Name of the ddosmitigator service
  /// </summary>
  virtual std::string getName() = 0;

  /// <summary>
  /// UUID of the Cube
  /// </summary>
  virtual std::string getUuid() = 0;

  /// <summary>
  /// Type of the Cube (TC, XDP_SKB, XDP_DRV)
  /// </summary>
  virtual CubeType getType() = 0;

  /// <summary>
  /// Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
  /// </summary>
  virtual DdosmitigatorLoglevelEnum getLoglevel() = 0;
  virtual void setLoglevel(const DdosmitigatorLoglevelEnum &value) = 0;

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
  ///
  /// </summary>
  virtual std::shared_ptr<Stats> getStats() = 0;
  virtual void addStats(const StatsJsonObject &value) = 0;
  virtual void replaceStats(const StatsJsonObject &conf) = 0;
  virtual void delStats() = 0;

  /// <summary>
  /// Port where the traffic is received
  /// </summary>
  virtual std::string getActivePort() = 0;
  virtual void setActivePort(const std::string &value) = 0;

  /// <summary>
  /// If set, this will be the port used to redirect traffic (instead of PASS it to STACK)
  /// </summary>
  virtual std::string getRedirectPort() = 0;
  virtual void setRedirectPort(const std::string &value) = 0;

  /// <summary>
  /// Blacklisted source IP addresses
  /// </summary>
  virtual std::shared_ptr<BlacklistSrc> getBlacklistSrc(const std::string &ip) = 0;
  virtual std::vector<std::shared_ptr<BlacklistSrc>> getBlacklistSrcList() = 0;
  virtual void addBlacklistSrc(const std::string &ip, const BlacklistSrcJsonObject &conf) = 0;
  virtual void addBlacklistSrcList(const std::vector<BlacklistSrcJsonObject> &conf) = 0;
  virtual void replaceBlacklistSrc(const std::string &ip, const BlacklistSrcJsonObject &conf) = 0;
  virtual void delBlacklistSrc(const std::string &ip) = 0;
  virtual void delBlacklistSrcList() = 0;

  /// <summary>
  /// Blacklisted destination IP addresses
  /// </summary>
  virtual std::shared_ptr<BlacklistDst> getBlacklistDst(const std::string &ip) = 0;
  virtual std::vector<std::shared_ptr<BlacklistDst>> getBlacklistDstList() = 0;
  virtual void addBlacklistDst(const std::string &ip, const BlacklistDstJsonObject &conf) = 0;
  virtual void addBlacklistDstList(const std::vector<BlacklistDstJsonObject> &conf) = 0;
  virtual void replaceBlacklistDst(const std::string &ip, const BlacklistDstJsonObject &conf) = 0;
  virtual void delBlacklistDst(const std::string &ip) = 0;
  virtual void delBlacklistDstList() = 0;
};
