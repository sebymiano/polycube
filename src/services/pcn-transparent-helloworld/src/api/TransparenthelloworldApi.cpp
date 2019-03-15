/**
* transparenthelloworld API
* transparenthelloworld API generated from transparenthelloworld.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */


#include "TransparenthelloworldApi.h"
#include "TransparenthelloworldApiImpl.h"

using namespace io::swagger::server::model;
using namespace io::swagger::server::api::TransparenthelloworldApiImpl;

#ifdef __cplusplus
extern "C" {
#endif

Response create_transparenthelloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    TransparenthelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    create_transparenthelloworld_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_transparenthelloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_transparenthelloworld_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_transparenthelloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_transparenthelloworld_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_transparenthelloworld_egress_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_transparenthelloworld_egress_action_by_id(unique_name);
    nlohmann::json response_body;
    response_body = TransparenthelloworldJsonObject::TransparenthelloworldEgressActionEnum_to_string(x);
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_transparenthelloworld_ingress_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_transparenthelloworld_ingress_action_by_id(unique_name);
    nlohmann::json response_body;
    response_body = TransparenthelloworldJsonObject::TransparenthelloworldIngressActionEnum_to_string(x);
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_transparenthelloworld_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {


  try {

    auto x = read_transparenthelloworld_list_by_id();
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_transparenthelloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    TransparenthelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    replace_transparenthelloworld_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_transparenthelloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    TransparenthelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    update_transparenthelloworld_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_transparenthelloworld_egress_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    TransparenthelloworldEgressActionEnum unique_value_ = TransparenthelloworldJsonObject::string_to_TransparenthelloworldEgressActionEnum(request_body);
    update_transparenthelloworld_egress_action_by_id(unique_name, unique_value_);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_transparenthelloworld_ingress_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    TransparenthelloworldIngressActionEnum unique_value_ = TransparenthelloworldJsonObject::string_to_TransparenthelloworldIngressActionEnum(request_body);
    update_transparenthelloworld_ingress_action_by_id(unique_name, unique_value_);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_transparenthelloworld_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {

  // Getting the body param
  std::vector<TransparenthelloworldJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<TransparenthelloworldJsonObject> unique_value;
    for (auto &j : request_body) {
      TransparenthelloworldJsonObject a { j };
      unique_value.push_back(a);
    }
    update_transparenthelloworld_list_by_id(unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}


Response transparenthelloworld_by_id_help(
  HelpType type, const char *name,
  const Key *keys, size_t num_keys) {
  // Getting the path params
  std::string unique_name { name };
  nlohmann::json val = nlohmann::json::object();
  switch (type) {
  case HelpType::SHOW:
    val["params"] = TransparenthelloworldJsonObject::helpElements();
  break;
  case HelpType::SET:
    val["params"] = TransparenthelloworldJsonObject::helpWritableLeafs();
  break;
  case HelpType::NONE:
    val["commands"] = {"set", "show"};
    val["params"] = TransparenthelloworldJsonObject::helpComplexElements();
    val["actions"] = TransparenthelloworldJsonObject::helpActions();
  break;
  default:
    return { kBadRequest, nullptr };
  }
  return { kOk, ::strdup(val.dump().c_str()) };
}

Response transparenthelloworld_list_by_id_help(
  HelpType type, const char *name,
  const Key *keys, size_t num_keys) {

  nlohmann::json val = nlohmann::json::object();
  switch (type) {
  case HelpType::SHOW:
    val["params"] = TransparenthelloworldJsonObject::helpKeys();
    val["elements"] = read_transparenthelloworld_list_by_id_get_list();
  break;
  case HelpType::ADD:
    val["params"] = TransparenthelloworldJsonObject::helpKeys();
    val["optional-params"] = TransparenthelloworldJsonObject::helpWritableLeafs();
  break;
  case HelpType::DEL:
    val["params"] = TransparenthelloworldJsonObject::helpKeys();
    val["elements"] = read_transparenthelloworld_list_by_id_get_list();
  break;
  case HelpType::NONE:
    val["commands"] = {"add", "del", "show"};
    val["params"] = TransparenthelloworldJsonObject::helpKeys();
    val["elements"] = read_transparenthelloworld_list_by_id_get_list();
  break;
  default:
    return { kBadRequest, nullptr };
  }
  return { kOk, ::strdup(val.dump().c_str()) };
}

#ifdef __cplusplus
}
#endif
