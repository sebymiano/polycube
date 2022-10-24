/**
* iptables API generated from iptables.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* IptablesApiImpl.h
*
*
*/

#pragma once


#include <memory>
#include <map>
#include <mutex>
#include "../Iptables.h"

#include "ChainJsonObject.h"
#include "ChainAppendInputJsonObject.h"
#include "ChainAppendOutputJsonObject.h"
#include "ChainApplyRulesOutputJsonObject.h"
#include "ChainInsertInputJsonObject.h"
#include "ChainInsertOutputJsonObject.h"
#include "ChainRemoveInputJsonObject.h"
#include "ChainResetCountersOutputJsonObject.h"
#include "ChainRuleJsonObject.h"
#include "ChainStatsJsonObject.h"
#include "IptablesJsonObject.h"
#include "PortsJsonObject.h"
#include "SessionTableJsonObject.h"
#include <vector>

namespace polycube {
namespace service {
namespace api {

using namespace polycube::service::model;

namespace IptablesApiImpl {
  void create_iptables_by_id(const std::string &name, const IptablesJsonObject &value);
  ChainAppendOutputJsonObject create_iptables_chain_append_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainAppendInputJsonObject &value);
  ChainApplyRulesOutputJsonObject create_iptables_chain_apply_rules_by_id(const std::string &name, const ChainNameEnum &chainName);
  void create_iptables_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value);
  ChainInsertOutputJsonObject create_iptables_chain_insert_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainInsertInputJsonObject &value);
  void create_iptables_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value);
  void create_iptables_chain_remove_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainRemoveInputJsonObject &value);
  ChainResetCountersOutputJsonObject create_iptables_chain_reset_counters_by_id(const std::string &name, const ChainNameEnum &chainName);
  void create_iptables_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value);
  void create_iptables_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value);
  void create_iptables_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void create_iptables_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void delete_iptables_by_id(const std::string &name);
  void delete_iptables_chain_by_id(const std::string &name, const ChainNameEnum &chainName);
  void delete_iptables_chain_list_by_id(const std::string &name);
  void delete_iptables_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  void delete_iptables_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName);
  void delete_iptables_ports_by_id(const std::string &name, const std::string &portsName);
  void delete_iptables_ports_list_by_id(const std::string &name);
  IptablesJsonObject read_iptables_by_id(const std::string &name);
  ChainJsonObject read_iptables_chain_by_id(const std::string &name, const ChainNameEnum &chainName);
  ActionEnum read_iptables_chain_default_by_id(const std::string &name, const ChainNameEnum &chainName);
  std::vector<ChainJsonObject> read_iptables_chain_list_by_id(const std::string &name);
  ActionEnum read_iptables_chain_rule_action_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  ChainRuleJsonObject read_iptables_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  ConntrackstatusEnum read_iptables_chain_rule_conntrack_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_dport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_dst_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_in_iface_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_l4proto_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::vector<ChainRuleJsonObject> read_iptables_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName);
  std::string read_iptables_chain_rule_out_iface_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_sport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_src_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_rule_tcpflags_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  ChainStatsJsonObject read_iptables_chain_stats_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  uint64_t read_iptables_chain_stats_bytes_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::string read_iptables_chain_stats_description_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  std::vector<ChainStatsJsonObject> read_iptables_chain_stats_list_by_id(const std::string &name, const ChainNameEnum &chainName);
  uint64_t read_iptables_chain_stats_pkts_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id);
  IptablesConntrackEnum read_iptables_conntrack_by_id(const std::string &name);
  bool read_iptables_dyn_opt_by_id(const std::string &name);
  IptablesHorusEnum read_iptables_horus_by_id(const std::string &name);
  bool read_iptables_interactive_by_id(const std::string &name);
  std::vector<IptablesJsonObject> read_iptables_list_by_id();
  PortsJsonObject read_iptables_ports_by_id(const std::string &name, const std::string &portsName);
  std::vector<PortsJsonObject> read_iptables_ports_list_by_id(const std::string &name);
  SessionTableJsonObject read_iptables_session_table_by_id(const std::string &name, const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport);
  std::vector<SessionTableJsonObject> read_iptables_session_table_list_by_id(const std::string &name);
  std::string read_iptables_session_table_state_by_id(const std::string &name, const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport);
  bool read_iptables_spinlocks_by_id(const std::string &name);
  bool read_iptables_start_morpheus_by_id(const std::string &name);
  void replace_iptables_by_id(const std::string &name, const IptablesJsonObject &value);
  void replace_iptables_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value);
  void replace_iptables_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value);
  void replace_iptables_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value);
  void replace_iptables_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value);
  void replace_iptables_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void replace_iptables_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void update_iptables_by_id(const std::string &name, const IptablesJsonObject &value);
  void update_iptables_chain_by_id(const std::string &name, const ChainNameEnum &chainName, const ChainJsonObject &value);
  void update_iptables_chain_default_by_id(const std::string &name, const ChainNameEnum &chainName, const ActionEnum &value);
  void update_iptables_chain_list_by_id(const std::string &name, const std::vector<ChainJsonObject> &value);
  void update_iptables_chain_rule_action_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ActionEnum &value);
  void update_iptables_chain_rule_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ChainRuleJsonObject &value);
  void update_iptables_chain_rule_conntrack_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const ConntrackstatusEnum &value);
  void update_iptables_chain_rule_dport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_dst_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_in_iface_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_l4proto_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_list_by_id(const std::string &name, const ChainNameEnum &chainName, const std::vector<ChainRuleJsonObject> &value);
  void update_iptables_chain_rule_out_iface_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_sport_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_src_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_chain_rule_tcpflags_by_id(const std::string &name, const ChainNameEnum &chainName, const uint32_t &id, const std::string &value);
  void update_iptables_conntrack_by_id(const std::string &name, const IptablesConntrackEnum &value);
  void update_iptables_horus_by_id(const std::string &name, const IptablesHorusEnum &value);
  void update_iptables_interactive_by_id(const std::string &name, const bool &value);
  void update_iptables_list_by_id(const std::vector<IptablesJsonObject> &value);
  void update_iptables_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value);
  void update_iptables_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value);
  void update_iptables_spinlocks_by_id(const std::string &name, const bool &value);
  void update_iptables_start_morpheus_by_id(const std::string &name, const bool &value);

  /* help related */
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_chain_list_by_id_get_list(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_chain_rule_list_by_id_get_list(const std::string &name, const ChainNameEnum &chainName);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_chain_stats_list_by_id_get_list(const std::string &name, const ChainNameEnum &chainName);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_list_by_id_get_list();
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_ports_list_by_id_get_list(const std::string &name);
  std::vector<nlohmann::fifo_map<std::string, std::string>> read_iptables_session_table_list_by_id_get_list(const std::string &name);

}
}
}
}

