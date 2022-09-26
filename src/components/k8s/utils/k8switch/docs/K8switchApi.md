# \K8switchApi

All URIs are relative to *http://localhost:8080*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CreateK8switchByID**](K8switchApi.md#CreateK8switchByID) | **Post** /k8switch/{name}/ | Create k8switch by ID
[**CreateK8switchFwdTableByID**](K8switchApi.md#CreateK8switchFwdTableByID) | **Post** /k8switch/{name}/fwd-table/{address}/ | Create fwd-table by ID
[**CreateK8switchFwdTableListByID**](K8switchApi.md#CreateK8switchFwdTableListByID) | **Post** /k8switch/{name}/fwd-table/ | Create fwd-table by ID
[**CreateK8switchPortsByID**](K8switchApi.md#CreateK8switchPortsByID) | **Post** /k8switch/{name}/ports/{ports_name}/ | Create ports by ID
[**CreateK8switchPortsListByID**](K8switchApi.md#CreateK8switchPortsListByID) | **Post** /k8switch/{name}/ports/ | Create ports by ID
[**CreateK8switchServiceBackendByID**](K8switchApi.md#CreateK8switchServiceBackendByID) | **Post** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/ | Create backend by ID
[**CreateK8switchServiceBackendListByID**](K8switchApi.md#CreateK8switchServiceBackendListByID) | **Post** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/ | Create backend by ID
[**CreateK8switchServiceByID**](K8switchApi.md#CreateK8switchServiceByID) | **Post** /k8switch/{name}/service/{vip}/{vport}/{proto}/ | Create service by ID
[**CreateK8switchServiceListByID**](K8switchApi.md#CreateK8switchServiceListByID) | **Post** /k8switch/{name}/service/ | Create service by ID
[**DeleteK8switchByID**](K8switchApi.md#DeleteK8switchByID) | **Delete** /k8switch/{name}/ | Delete k8switch by ID
[**DeleteK8switchFwdTableByID**](K8switchApi.md#DeleteK8switchFwdTableByID) | **Delete** /k8switch/{name}/fwd-table/{address}/ | Delete fwd-table by ID
[**DeleteK8switchFwdTableListByID**](K8switchApi.md#DeleteK8switchFwdTableListByID) | **Delete** /k8switch/{name}/fwd-table/ | Delete fwd-table by ID
[**DeleteK8switchPortsByID**](K8switchApi.md#DeleteK8switchPortsByID) | **Delete** /k8switch/{name}/ports/{ports_name}/ | Delete ports by ID
[**DeleteK8switchPortsListByID**](K8switchApi.md#DeleteK8switchPortsListByID) | **Delete** /k8switch/{name}/ports/ | Delete ports by ID
[**DeleteK8switchServiceBackendByID**](K8switchApi.md#DeleteK8switchServiceBackendByID) | **Delete** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/ | Delete backend by ID
[**DeleteK8switchServiceBackendListByID**](K8switchApi.md#DeleteK8switchServiceBackendListByID) | **Delete** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/ | Delete backend by ID
[**DeleteK8switchServiceByID**](K8switchApi.md#DeleteK8switchServiceByID) | **Delete** /k8switch/{name}/service/{vip}/{vport}/{proto}/ | Delete service by ID
[**DeleteK8switchServiceListByID**](K8switchApi.md#DeleteK8switchServiceListByID) | **Delete** /k8switch/{name}/service/ | Delete service by ID
[**ReadK8switchByID**](K8switchApi.md#ReadK8switchByID) | **Get** /k8switch/{name}/ | Read k8switch by ID
[**ReadK8switchClientSubnetByID**](K8switchApi.md#ReadK8switchClientSubnetByID) | **Get** /k8switch/{name}/client-subnet/ | Read client-subnet by ID
[**ReadK8switchClusterIpSubnetByID**](K8switchApi.md#ReadK8switchClusterIpSubnetByID) | **Get** /k8switch/{name}/cluster-ip-subnet/ | Read cluster-ip-subnet by ID
[**ReadK8switchDynOptByID**](K8switchApi.md#ReadK8switchDynOptByID) | **Get** /k8switch/{name}/dyn-opt/ | Read dyn-opt by ID
[**ReadK8switchFwdTableByID**](K8switchApi.md#ReadK8switchFwdTableByID) | **Get** /k8switch/{name}/fwd-table/{address}/ | Read fwd-table by ID
[**ReadK8switchFwdTableListByID**](K8switchApi.md#ReadK8switchFwdTableListByID) | **Get** /k8switch/{name}/fwd-table/ | Read fwd-table by ID
[**ReadK8switchFwdTableMacByID**](K8switchApi.md#ReadK8switchFwdTableMacByID) | **Get** /k8switch/{name}/fwd-table/{address}/mac/ | Read mac by ID
[**ReadK8switchFwdTablePortByID**](K8switchApi.md#ReadK8switchFwdTablePortByID) | **Get** /k8switch/{name}/fwd-table/{address}/port/ | Read port by ID
[**ReadK8switchListByID**](K8switchApi.md#ReadK8switchListByID) | **Get** /k8switch/ | Read k8switch by ID
[**ReadK8switchLoglevelByID**](K8switchApi.md#ReadK8switchLoglevelByID) | **Get** /k8switch/{name}/loglevel/ | Read loglevel by ID
[**ReadK8switchPortsByID**](K8switchApi.md#ReadK8switchPortsByID) | **Get** /k8switch/{name}/ports/{ports_name}/ | Read ports by ID
[**ReadK8switchPortsListByID**](K8switchApi.md#ReadK8switchPortsListByID) | **Get** /k8switch/{name}/ports/ | Read ports by ID
[**ReadK8switchPortsPeerByID**](K8switchApi.md#ReadK8switchPortsPeerByID) | **Get** /k8switch/{name}/ports/{ports_name}/peer/ | Read peer by ID
[**ReadK8switchPortsStatusByID**](K8switchApi.md#ReadK8switchPortsStatusByID) | **Get** /k8switch/{name}/ports/{ports_name}/status/ | Read status by ID
[**ReadK8switchPortsTypeByID**](K8switchApi.md#ReadK8switchPortsTypeByID) | **Get** /k8switch/{name}/ports/{ports_name}/type/ | Read type by ID
[**ReadK8switchPortsUuidByID**](K8switchApi.md#ReadK8switchPortsUuidByID) | **Get** /k8switch/{name}/ports/{ports_name}/uuid/ | Read uuid by ID
[**ReadK8switchServiceBackendByID**](K8switchApi.md#ReadK8switchServiceBackendByID) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/ | Read backend by ID
[**ReadK8switchServiceBackendListByID**](K8switchApi.md#ReadK8switchServiceBackendListByID) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/ | Read backend by ID
[**ReadK8switchServiceBackendNameByID**](K8switchApi.md#ReadK8switchServiceBackendNameByID) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/name/ | Read name by ID
[**ReadK8switchServiceBackendWeightByID**](K8switchApi.md#ReadK8switchServiceBackendWeightByID) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/weight/ | Read weight by ID
[**ReadK8switchServiceByID**](K8switchApi.md#ReadK8switchServiceByID) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/ | Read service by ID
[**ReadK8switchServiceListByID**](K8switchApi.md#ReadK8switchServiceListByID) | **Get** /k8switch/{name}/service/ | Read service by ID
[**ReadK8switchServiceNameByID**](K8switchApi.md#ReadK8switchServiceNameByID) | **Get** /k8switch/{name}/service-name/ | Read service-name by ID
[**ReadK8switchServiceNameByID_0**](K8switchApi.md#ReadK8switchServiceNameByID_0) | **Get** /k8switch/{name}/service/{vip}/{vport}/{proto}/name/ | Read name by ID
[**ReadK8switchShadowByID**](K8switchApi.md#ReadK8switchShadowByID) | **Get** /k8switch/{name}/shadow/ | Read shadow by ID
[**ReadK8switchSpanByID**](K8switchApi.md#ReadK8switchSpanByID) | **Get** /k8switch/{name}/span/ | Read span by ID
[**ReadK8switchStartMorpheusByID**](K8switchApi.md#ReadK8switchStartMorpheusByID) | **Get** /k8switch/{name}/start-morpheus/ | Read start-morpheus by ID
[**ReadK8switchTypeByID**](K8switchApi.md#ReadK8switchTypeByID) | **Get** /k8switch/{name}/type/ | Read type by ID
[**ReadK8switchUuidByID**](K8switchApi.md#ReadK8switchUuidByID) | **Get** /k8switch/{name}/uuid/ | Read uuid by ID
[**ReadK8switchVirtualClientSubnetByID**](K8switchApi.md#ReadK8switchVirtualClientSubnetByID) | **Get** /k8switch/{name}/virtual-client-subnet/ | Read virtual-client-subnet by ID
[**ReplaceK8switchByID**](K8switchApi.md#ReplaceK8switchByID) | **Put** /k8switch/{name}/ | Replace k8switch by ID
[**ReplaceK8switchFwdTableByID**](K8switchApi.md#ReplaceK8switchFwdTableByID) | **Put** /k8switch/{name}/fwd-table/{address}/ | Replace fwd-table by ID
[**ReplaceK8switchFwdTableListByID**](K8switchApi.md#ReplaceK8switchFwdTableListByID) | **Put** /k8switch/{name}/fwd-table/ | Replace fwd-table by ID
[**ReplaceK8switchPortsByID**](K8switchApi.md#ReplaceK8switchPortsByID) | **Put** /k8switch/{name}/ports/{ports_name}/ | Replace ports by ID
[**ReplaceK8switchPortsListByID**](K8switchApi.md#ReplaceK8switchPortsListByID) | **Put** /k8switch/{name}/ports/ | Replace ports by ID
[**ReplaceK8switchServiceBackendByID**](K8switchApi.md#ReplaceK8switchServiceBackendByID) | **Put** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/ | Replace backend by ID
[**ReplaceK8switchServiceBackendListByID**](K8switchApi.md#ReplaceK8switchServiceBackendListByID) | **Put** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/ | Replace backend by ID
[**ReplaceK8switchServiceByID**](K8switchApi.md#ReplaceK8switchServiceByID) | **Put** /k8switch/{name}/service/{vip}/{vport}/{proto}/ | Replace service by ID
[**ReplaceK8switchServiceListByID**](K8switchApi.md#ReplaceK8switchServiceListByID) | **Put** /k8switch/{name}/service/ | Replace service by ID
[**UpdateK8switchByID**](K8switchApi.md#UpdateK8switchByID) | **Patch** /k8switch/{name}/ | Update k8switch by ID
[**UpdateK8switchClientSubnetByID**](K8switchApi.md#UpdateK8switchClientSubnetByID) | **Patch** /k8switch/{name}/client-subnet/ | Update client-subnet by ID
[**UpdateK8switchClusterIpSubnetByID**](K8switchApi.md#UpdateK8switchClusterIpSubnetByID) | **Patch** /k8switch/{name}/cluster-ip-subnet/ | Update cluster-ip-subnet by ID
[**UpdateK8switchFwdTableByID**](K8switchApi.md#UpdateK8switchFwdTableByID) | **Patch** /k8switch/{name}/fwd-table/{address}/ | Update fwd-table by ID
[**UpdateK8switchFwdTableListByID**](K8switchApi.md#UpdateK8switchFwdTableListByID) | **Patch** /k8switch/{name}/fwd-table/ | Update fwd-table by ID
[**UpdateK8switchFwdTableMacByID**](K8switchApi.md#UpdateK8switchFwdTableMacByID) | **Patch** /k8switch/{name}/fwd-table/{address}/mac/ | Update mac by ID
[**UpdateK8switchFwdTablePortByID**](K8switchApi.md#UpdateK8switchFwdTablePortByID) | **Patch** /k8switch/{name}/fwd-table/{address}/port/ | Update port by ID
[**UpdateK8switchListByID**](K8switchApi.md#UpdateK8switchListByID) | **Patch** /k8switch/ | Update k8switch by ID
[**UpdateK8switchLoglevelByID**](K8switchApi.md#UpdateK8switchLoglevelByID) | **Patch** /k8switch/{name}/loglevel/ | Update loglevel by ID
[**UpdateK8switchPortsByID**](K8switchApi.md#UpdateK8switchPortsByID) | **Patch** /k8switch/{name}/ports/{ports_name}/ | Update ports by ID
[**UpdateK8switchPortsListByID**](K8switchApi.md#UpdateK8switchPortsListByID) | **Patch** /k8switch/{name}/ports/ | Update ports by ID
[**UpdateK8switchPortsPeerByID**](K8switchApi.md#UpdateK8switchPortsPeerByID) | **Patch** /k8switch/{name}/ports/{ports_name}/peer/ | Update peer by ID
[**UpdateK8switchServiceBackendByID**](K8switchApi.md#UpdateK8switchServiceBackendByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/ | Update backend by ID
[**UpdateK8switchServiceBackendListByID**](K8switchApi.md#UpdateK8switchServiceBackendListByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/ | Update backend by ID
[**UpdateK8switchServiceBackendNameByID**](K8switchApi.md#UpdateK8switchServiceBackendNameByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/name/ | Update name by ID
[**UpdateK8switchServiceBackendWeightByID**](K8switchApi.md#UpdateK8switchServiceBackendWeightByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/backend/{ip}/{port}/weight/ | Update weight by ID
[**UpdateK8switchServiceByID**](K8switchApi.md#UpdateK8switchServiceByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/ | Update service by ID
[**UpdateK8switchServiceListByID**](K8switchApi.md#UpdateK8switchServiceListByID) | **Patch** /k8switch/{name}/service/ | Update service by ID
[**UpdateK8switchServiceNameByID**](K8switchApi.md#UpdateK8switchServiceNameByID) | **Patch** /k8switch/{name}/service/{vip}/{vport}/{proto}/name/ | Update name by ID
[**UpdateK8switchSpanByID**](K8switchApi.md#UpdateK8switchSpanByID) | **Patch** /k8switch/{name}/span/ | Update span by ID
[**UpdateK8switchStartMorpheusByID**](K8switchApi.md#UpdateK8switchStartMorpheusByID) | **Patch** /k8switch/{name}/start-morpheus/ | Update start-morpheus by ID
[**UpdateK8switchVirtualClientSubnetByID**](K8switchApi.md#UpdateK8switchVirtualClientSubnetByID) | **Patch** /k8switch/{name}/virtual-client-subnet/ | Update virtual-client-subnet by ID


# **CreateK8switchByID**
> CreateK8switchByID(ctx, name, k8switch)
Create k8switch by ID

Create operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8switch** | [**K8switch**](K8switch.md)| k8switchbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchFwdTableByID**
> CreateK8switchFwdTableByID(ctx, name, address, fwdTable)
Create fwd-table by ID

Create operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 
  **fwdTable** | [**FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchFwdTableListByID**
> CreateK8switchFwdTableListByID(ctx, name, fwdTable)
Create fwd-table by ID

Create operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **fwdTable** | [**[]FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchPortsByID**
> CreateK8switchPortsByID(ctx, name, portsName, ports)
Create ports by ID

Create operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 
  **ports** | [**Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchPortsListByID**
> CreateK8switchPortsListByID(ctx, name, ports)
Create ports by ID

Create operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **ports** | [**[]Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchServiceBackendByID**
> CreateK8switchServiceBackendByID(ctx, name, vip, vport, proto, ip, port, backend)
Create backend by ID

Create operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 
  **backend** | [**ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchServiceBackendListByID**
> CreateK8switchServiceBackendListByID(ctx, name, vip, vport, proto, backend)
Create backend by ID

Create operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **backend** | [**[]ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchServiceByID**
> CreateK8switchServiceByID(ctx, name, vip, vport, proto, service)
Create service by ID

Create operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **service** | [**Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8switchServiceListByID**
> CreateK8switchServiceListByID(ctx, name, service)
Create service by ID

Create operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **service** | [**[]Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchByID**
> DeleteK8switchByID(ctx, name)
Delete k8switch by ID

Delete operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchFwdTableByID**
> DeleteK8switchFwdTableByID(ctx, name, address)
Delete fwd-table by ID

Delete operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchFwdTableListByID**
> DeleteK8switchFwdTableListByID(ctx, name)
Delete fwd-table by ID

Delete operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchPortsByID**
> DeleteK8switchPortsByID(ctx, name, portsName)
Delete ports by ID

Delete operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchPortsListByID**
> DeleteK8switchPortsListByID(ctx, name)
Delete ports by ID

Delete operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchServiceBackendByID**
> DeleteK8switchServiceBackendByID(ctx, name, vip, vport, proto, ip, port)
Delete backend by ID

Delete operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchServiceBackendListByID**
> DeleteK8switchServiceBackendListByID(ctx, name, vip, vport, proto)
Delete backend by ID

Delete operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchServiceByID**
> DeleteK8switchServiceByID(ctx, name, vip, vport, proto)
Delete service by ID

Delete operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DeleteK8switchServiceListByID**
> DeleteK8switchServiceListByID(ctx, name)
Delete service by ID

Delete operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchByID**
> K8switch ReadK8switchByID(ctx, name)
Read k8switch by ID

Read operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

[**K8switch**](K8switch.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchClientSubnetByID**
> string ReadK8switchClientSubnetByID(ctx, name)
Read client-subnet by ID

Read operation of resource: client-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchClusterIpSubnetByID**
> string ReadK8switchClusterIpSubnetByID(ctx, name)
Read cluster-ip-subnet by ID

Read operation of resource: cluster-ip-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchDynOptByID**
> bool ReadK8switchDynOptByID(ctx, name)
Read dyn-opt by ID

Read operation of resource: dyn-opt

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**bool**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchFwdTableByID**
> FwdTable ReadK8switchFwdTableByID(ctx, name, address)
Read fwd-table by ID

Read operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 

### Return type

[**FwdTable**](FwdTable.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchFwdTableListByID**
> []FwdTable ReadK8switchFwdTableListByID(ctx, name)
Read fwd-table by ID

Read operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

[**[]FwdTable**](FwdTable.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchFwdTableMacByID**
> string ReadK8switchFwdTableMacByID(ctx, name, address)
Read mac by ID

Read operation of resource: mac

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchFwdTablePortByID**
> string ReadK8switchFwdTablePortByID(ctx, name, address)
Read port by ID

Read operation of resource: port

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchListByID**
> []K8switch ReadK8switchListByID(ctx, )
Read k8switch by ID

Read operation of resource: k8switch

### Required Parameters
This endpoint does not need any parameter.

### Return type

[**[]K8switch**](K8switch.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchLoglevelByID**
> string ReadK8switchLoglevelByID(ctx, name)
Read loglevel by ID

Read operation of resource: loglevel

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsByID**
> Ports ReadK8switchPortsByID(ctx, name, portsName)
Read ports by ID

Read operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

[**Ports**](Ports.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsListByID**
> []Ports ReadK8switchPortsListByID(ctx, name)
Read ports by ID

Read operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

[**[]Ports**](Ports.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsPeerByID**
> string ReadK8switchPortsPeerByID(ctx, name, portsName)
Read peer by ID

Read operation of resource: peer

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsStatusByID**
> string ReadK8switchPortsStatusByID(ctx, name, portsName)
Read status by ID

Read operation of resource: status

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsTypeByID**
> string ReadK8switchPortsTypeByID(ctx, name, portsName)
Read type by ID

Read operation of resource: type

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchPortsUuidByID**
> string ReadK8switchPortsUuidByID(ctx, name, portsName)
Read uuid by ID

Read operation of resource: uuid

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceBackendByID**
> ServiceBackend ReadK8switchServiceBackendByID(ctx, name, vip, vport, proto, ip, port)
Read backend by ID

Read operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 

### Return type

[**ServiceBackend**](ServiceBackend.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceBackendListByID**
> []ServiceBackend ReadK8switchServiceBackendListByID(ctx, name, vip, vport, proto)
Read backend by ID

Read operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 

### Return type

[**[]ServiceBackend**](ServiceBackend.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceBackendNameByID**
> string ReadK8switchServiceBackendNameByID(ctx, name, vip, vport, proto, ip, port)
Read name by ID

Read operation of resource: name

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceBackendWeightByID**
> int32 ReadK8switchServiceBackendWeightByID(ctx, name, vip, vport, proto, ip, port)
Read weight by ID

Read operation of resource: weight

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 

### Return type

**int32**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceByID**
> Service ReadK8switchServiceByID(ctx, name, vip, vport, proto)
Read service by ID

Read operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 

### Return type

[**Service**](Service.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceListByID**
> []Service ReadK8switchServiceListByID(ctx, name)
Read service by ID

Read operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

[**[]Service**](Service.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceNameByID**
> string ReadK8switchServiceNameByID(ctx, name)
Read service-name by ID

Read operation of resource: service-name

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchServiceNameByID_0**
> string ReadK8switchServiceNameByID_0(ctx, name, vip, vport, proto)
Read name by ID

Read operation of resource: name

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchShadowByID**
> bool ReadK8switchShadowByID(ctx, name)
Read shadow by ID

Read operation of resource: shadow

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**bool**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchSpanByID**
> bool ReadK8switchSpanByID(ctx, name)
Read span by ID

Read operation of resource: span

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**bool**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchStartMorpheusByID**
> bool ReadK8switchStartMorpheusByID(ctx, name)
Read start-morpheus by ID

Read operation of resource: start-morpheus

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**bool**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchTypeByID**
> string ReadK8switchTypeByID(ctx, name)
Read type by ID

Read operation of resource: type

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchUuidByID**
> string ReadK8switchUuidByID(ctx, name)
Read uuid by ID

Read operation of resource: uuid

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8switchVirtualClientSubnetByID**
> string ReadK8switchVirtualClientSubnetByID(ctx, name)
Read virtual-client-subnet by ID

Read operation of resource: virtual-client-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchByID**
> ReplaceK8switchByID(ctx, name, k8switch)
Replace k8switch by ID

Replace operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8switch** | [**K8switch**](K8switch.md)| k8switchbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchFwdTableByID**
> ReplaceK8switchFwdTableByID(ctx, name, address, fwdTable)
Replace fwd-table by ID

Replace operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 
  **fwdTable** | [**FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchFwdTableListByID**
> ReplaceK8switchFwdTableListByID(ctx, name, fwdTable)
Replace fwd-table by ID

Replace operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **fwdTable** | [**[]FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchPortsByID**
> ReplaceK8switchPortsByID(ctx, name, portsName, ports)
Replace ports by ID

Replace operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 
  **ports** | [**Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchPortsListByID**
> ReplaceK8switchPortsListByID(ctx, name, ports)
Replace ports by ID

Replace operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **ports** | [**[]Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchServiceBackendByID**
> ReplaceK8switchServiceBackendByID(ctx, name, vip, vport, proto, ip, port, backend)
Replace backend by ID

Replace operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 
  **backend** | [**ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchServiceBackendListByID**
> ReplaceK8switchServiceBackendListByID(ctx, name, vip, vport, proto, backend)
Replace backend by ID

Replace operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **backend** | [**[]ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchServiceByID**
> ReplaceK8switchServiceByID(ctx, name, vip, vport, proto, service)
Replace service by ID

Replace operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **service** | [**Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8switchServiceListByID**
> ReplaceK8switchServiceListByID(ctx, name, service)
Replace service by ID

Replace operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **service** | [**[]Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchByID**
> UpdateK8switchByID(ctx, name, k8switch)
Update k8switch by ID

Update operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8switch** | [**K8switch**](K8switch.md)| k8switchbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchClientSubnetByID**
> UpdateK8switchClientSubnetByID(ctx, name, clientSubnet)
Update client-subnet by ID

Update operation of resource: client-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **clientSubnet** | **string**| Range of IPs of pods in this node | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchClusterIpSubnetByID**
> UpdateK8switchClusterIpSubnetByID(ctx, name, clusterIpSubnet)
Update cluster-ip-subnet by ID

Update operation of resource: cluster-ip-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **clusterIpSubnet** | **string**| Range of VIPs where clusterIP services are exposed | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchFwdTableByID**
> UpdateK8switchFwdTableByID(ctx, name, address, fwdTable)
Update fwd-table by ID

Update operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 
  **fwdTable** | [**FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchFwdTableListByID**
> UpdateK8switchFwdTableListByID(ctx, name, fwdTable)
Update fwd-table by ID

Update operation of resource: fwd-table

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **fwdTable** | [**[]FwdTable**](FwdTable.md)| fwd-tablebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchFwdTableMacByID**
> UpdateK8switchFwdTableMacByID(ctx, name, address, mac)
Update mac by ID

Update operation of resource: mac

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 
  **mac** | **string**| Destination MAC address | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchFwdTablePortByID**
> UpdateK8switchFwdTablePortByID(ctx, name, address, port)
Update port by ID

Update operation of resource: port

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **address** | **string**| ID of address | 
  **port** | **string**| Port where this entry is present | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchListByID**
> UpdateK8switchListByID(ctx, k8switch)
Update k8switch by ID

Update operation of resource: k8switch

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **k8switch** | [**[]K8switch**](K8switch.md)| k8switchbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchLoglevelByID**
> UpdateK8switchLoglevelByID(ctx, name, loglevel)
Update loglevel by ID

Update operation of resource: loglevel

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **loglevel** | **string**| Logging level of a cube, from none (OFF) to the most verbose (TRACE) | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchPortsByID**
> UpdateK8switchPortsByID(ctx, name, portsName, ports)
Update ports by ID

Update operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 
  **ports** | [**Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchPortsListByID**
> UpdateK8switchPortsListByID(ctx, name, ports)
Update ports by ID

Update operation of resource: ports

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **ports** | [**[]Ports**](Ports.md)| portsbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchPortsPeerByID**
> UpdateK8switchPortsPeerByID(ctx, name, portsName, peer)
Update peer by ID

Update operation of resource: peer

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **portsName** | **string**| ID of ports_name | 
  **peer** | **string**| Peer name, such as a network interfaces (e.g., &#39;veth0&#39;) or another cube (e.g., &#39;br1:port2&#39;) | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceBackendByID**
> UpdateK8switchServiceBackendByID(ctx, name, vip, vport, proto, ip, port, backend)
Update backend by ID

Update operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 
  **backend** | [**ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceBackendListByID**
> UpdateK8switchServiceBackendListByID(ctx, name, vip, vport, proto, backend)
Update backend by ID

Update operation of resource: backend

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **backend** | [**[]ServiceBackend**](ServiceBackend.md)| backendbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceBackendNameByID**
> UpdateK8switchServiceBackendNameByID(ctx, name, vip, vport, proto, ip, port, name2)
Update name by ID

Update operation of resource: name

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 
  **name2** | **string**| name | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceBackendWeightByID**
> UpdateK8switchServiceBackendWeightByID(ctx, name, vip, vport, proto, ip, port, weight)
Update weight by ID

Update operation of resource: weight

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **ip** | **string**| ID of ip | 
  **port** | **int32**| ID of port | 
  **weight** | **int32**| Weight of the backend in the pool | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceByID**
> UpdateK8switchServiceByID(ctx, name, vip, vport, proto, service)
Update service by ID

Update operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **service** | [**Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceListByID**
> UpdateK8switchServiceListByID(ctx, name, service)
Update service by ID

Update operation of resource: service

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **service** | [**[]Service**](Service.md)| servicebody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchServiceNameByID**
> UpdateK8switchServiceNameByID(ctx, name, vip, vport, proto, name2)
Update name by ID

Update operation of resource: name

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **vip** | **string**| ID of vip | 
  **vport** | **int32**| ID of vport | 
  **proto** | **string**| ID of proto | 
  **name2** | **string**| Service name related to the backend server of the pool is connected to | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchSpanByID**
> UpdateK8switchSpanByID(ctx, name, span)
Update span by ID

Update operation of resource: span

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **span** | **bool**| Defines if all traffic is sent to Linux | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchStartMorpheusByID**
> UpdateK8switchStartMorpheusByID(ctx, name, startMorpheus)
Update start-morpheus by ID

Update operation of resource: start-morpheus

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **startMorpheus** | **bool**| Set this flag if you want to start Morpheus compiler | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8switchVirtualClientSubnetByID**
> UpdateK8switchVirtualClientSubnetByID(ctx, name, virtualClientSubnet)
Update virtual-client-subnet by ID

Update operation of resource: virtual-client-subnet

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **virtualClientSubnet** | **string**| Range where client&#39;s IPs are mapped into | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

