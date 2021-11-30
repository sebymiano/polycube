/**
* iptables API generated from iptables.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* ChainApplyRulesOutputJsonObject.h
*
*
*/

#pragma once


#include "JsonObjectBase.h"


namespace polycube {
namespace service {
namespace model {


/// <summary>
///
/// </summary>
class  ChainApplyRulesOutputJsonObject : public JsonObjectBase {
public:
  ChainApplyRulesOutputJsonObject();
  ChainApplyRulesOutputJsonObject(const nlohmann::json &json);
  ~ChainApplyRulesOutputJsonObject() final = default;
  nlohmann::json toJson() const final;


  /// <summary>
  /// True if the operation is successful
  /// </summary>
  bool getResult() const;
  void setResult(bool value);
  bool resultIsSet() const;
  void unsetResult();

private:
  bool m_result;
  bool m_resultIsSet;
};

}
}
}

