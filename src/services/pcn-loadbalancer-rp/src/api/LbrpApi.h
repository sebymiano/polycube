/**
* lbrp API generated from lbrp.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */

/*
* LbrpApi.h
*
*/

#pragma once

#define POLYCUBE_SERVICE_NAME "lbrp"


#include "polycube/services/response.h"
#include "polycube/services/shared_lib_elements.h"

#include "LbrpJsonObject.h"
#include "PortsJsonObject.h"
#include "ServiceJsonObject.h"
#include "ServiceBackendJsonObject.h"
#include "SrcIpRewriteJsonObject.h"
#include <vector>


#ifdef __cplusplus
extern "C" {
#endif

Response create_lbrp_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_ports_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_ports_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_service_backend_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_service_backend_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_service_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_service_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response create_lbrp_src_ip_rewrite_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response delete_lbrp_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_ports_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_ports_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_service_backend_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_service_backend_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_service_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_service_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response delete_lbrp_src_ip_rewrite_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_dyn_opt_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_port_mode_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_ports_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_ports_ip_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_ports_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_ports_type_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_backend_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_backend_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_backend_name_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_backend_port_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_backend_weight_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_list_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_service_name_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_src_ip_rewrite_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_src_ip_rewrite_ip_range_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_src_ip_rewrite_new_ip_range_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response read_lbrp_start_morpheus_by_id_handler(const char *name, const Key *keys, size_t num_keys);
Response replace_lbrp_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_ports_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_ports_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_service_backend_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_service_backend_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_service_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_service_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response replace_lbrp_src_ip_rewrite_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_port_mode_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_ports_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_ports_ip_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_ports_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_ports_type_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_backend_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_backend_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_backend_name_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_backend_port_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_backend_weight_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_list_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_service_name_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_src_ip_rewrite_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_src_ip_rewrite_ip_range_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_src_ip_rewrite_new_ip_range_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);
Response update_lbrp_start_morpheus_by_id_handler(const char *name, const Key *keys, size_t num_keys, const char *value);

Response lbrp_list_by_id_help(const char *name, const Key *keys, size_t num_keys);
Response lbrp_ports_list_by_id_help(const char *name, const Key *keys, size_t num_keys);
Response lbrp_service_backend_list_by_id_help(const char *name, const Key *keys, size_t num_keys);
Response lbrp_service_list_by_id_help(const char *name, const Key *keys, size_t num_keys);


#ifdef __cplusplus
}
#endif

