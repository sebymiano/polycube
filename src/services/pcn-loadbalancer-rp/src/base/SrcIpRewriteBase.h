/**
* lbrp API generated from lbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* SrcIpRewriteBase.h
*
*
*/

#pragma once

#include "../serializer/SrcIpRewriteJsonObject.h"






#include <spdlog/spdlog.h>

using namespace polycube::service::model;

class Lbrp;

class SrcIpRewriteBase {
 public:
  
  SrcIpRewriteBase(Lbrp &parent);
  
  virtual ~SrcIpRewriteBase();
  virtual void update(const SrcIpRewriteJsonObject &conf);
  virtual SrcIpRewriteJsonObject toJsonObject();

  /// <summary>
  /// Range of IP addresses of the clients that must be replaced
  /// </summary>
  virtual std::string getIpRange() = 0;
  virtual void setIpRange(const std::string &value) = 0;

  /// <summary>
  /// Range of IP addresses of the that must be used to replace client addresses
  /// </summary>
  virtual std::string getNewIpRange() = 0;
  virtual void setNewIpRange(const std::string &value) = 0;

  std::shared_ptr<spdlog::logger> logger();
 protected:
  Lbrp &parent_;
};