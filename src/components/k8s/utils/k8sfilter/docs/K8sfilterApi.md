# \K8sfilterApi

All URIs are relative to *http://localhost:8080*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CreateK8sfilterByID**](K8sfilterApi.md#CreateK8sfilterByID) | **Post** /k8sfilter/{name}/ | Create k8sfilter by ID
[**CreateK8sfilterPortsByID**](K8sfilterApi.md#CreateK8sfilterPortsByID) | **Post** /k8sfilter/{name}/ports/{ports_name}/ | Create ports by ID
[**CreateK8sfilterPortsListByID**](K8sfilterApi.md#CreateK8sfilterPortsListByID) | **Post** /k8sfilter/{name}/ports/ | Create ports by ID
[**DeleteK8sfilterByID**](K8sfilterApi.md#DeleteK8sfilterByID) | **Delete** /k8sfilter/{name}/ | Delete k8sfilter by ID
[**DeleteK8sfilterPortsByID**](K8sfilterApi.md#DeleteK8sfilterPortsByID) | **Delete** /k8sfilter/{name}/ports/{ports_name}/ | Delete ports by ID
[**DeleteK8sfilterPortsListByID**](K8sfilterApi.md#DeleteK8sfilterPortsListByID) | **Delete** /k8sfilter/{name}/ports/ | Delete ports by ID
[**ReadK8sfilterByID**](K8sfilterApi.md#ReadK8sfilterByID) | **Get** /k8sfilter/{name}/ | Read k8sfilter by ID
[**ReadK8sfilterDynOptByID**](K8sfilterApi.md#ReadK8sfilterDynOptByID) | **Get** /k8sfilter/{name}/dyn-opt/ | Read dyn-opt by ID
[**ReadK8sfilterListByID**](K8sfilterApi.md#ReadK8sfilterListByID) | **Get** /k8sfilter/ | Read k8sfilter by ID
[**ReadK8sfilterLoglevelByID**](K8sfilterApi.md#ReadK8sfilterLoglevelByID) | **Get** /k8sfilter/{name}/loglevel/ | Read loglevel by ID
[**ReadK8sfilterNodeportRangeByID**](K8sfilterApi.md#ReadK8sfilterNodeportRangeByID) | **Get** /k8sfilter/{name}/nodeport-range/ | Read nodeport-range by ID
[**ReadK8sfilterPortsByID**](K8sfilterApi.md#ReadK8sfilterPortsByID) | **Get** /k8sfilter/{name}/ports/{ports_name}/ | Read ports by ID
[**ReadK8sfilterPortsListByID**](K8sfilterApi.md#ReadK8sfilterPortsListByID) | **Get** /k8sfilter/{name}/ports/ | Read ports by ID
[**ReadK8sfilterPortsPeerByID**](K8sfilterApi.md#ReadK8sfilterPortsPeerByID) | **Get** /k8sfilter/{name}/ports/{ports_name}/peer/ | Read peer by ID
[**ReadK8sfilterPortsStatusByID**](K8sfilterApi.md#ReadK8sfilterPortsStatusByID) | **Get** /k8sfilter/{name}/ports/{ports_name}/status/ | Read status by ID
[**ReadK8sfilterPortsTypeByID**](K8sfilterApi.md#ReadK8sfilterPortsTypeByID) | **Get** /k8sfilter/{name}/ports/{ports_name}/type/ | Read type by ID
[**ReadK8sfilterPortsUuidByID**](K8sfilterApi.md#ReadK8sfilterPortsUuidByID) | **Get** /k8sfilter/{name}/ports/{ports_name}/uuid/ | Read uuid by ID
[**ReadK8sfilterServiceNameByID**](K8sfilterApi.md#ReadK8sfilterServiceNameByID) | **Get** /k8sfilter/{name}/service-name/ | Read service-name by ID
[**ReadK8sfilterShadowByID**](K8sfilterApi.md#ReadK8sfilterShadowByID) | **Get** /k8sfilter/{name}/shadow/ | Read shadow by ID
[**ReadK8sfilterSpanByID**](K8sfilterApi.md#ReadK8sfilterSpanByID) | **Get** /k8sfilter/{name}/span/ | Read span by ID
[**ReadK8sfilterStartMorpheusByID**](K8sfilterApi.md#ReadK8sfilterStartMorpheusByID) | **Get** /k8sfilter/{name}/start-morpheus/ | Read start-morpheus by ID
[**ReadK8sfilterTypeByID**](K8sfilterApi.md#ReadK8sfilterTypeByID) | **Get** /k8sfilter/{name}/type/ | Read type by ID
[**ReadK8sfilterUuidByID**](K8sfilterApi.md#ReadK8sfilterUuidByID) | **Get** /k8sfilter/{name}/uuid/ | Read uuid by ID
[**ReplaceK8sfilterByID**](K8sfilterApi.md#ReplaceK8sfilterByID) | **Put** /k8sfilter/{name}/ | Replace k8sfilter by ID
[**ReplaceK8sfilterPortsByID**](K8sfilterApi.md#ReplaceK8sfilterPortsByID) | **Put** /k8sfilter/{name}/ports/{ports_name}/ | Replace ports by ID
[**ReplaceK8sfilterPortsListByID**](K8sfilterApi.md#ReplaceK8sfilterPortsListByID) | **Put** /k8sfilter/{name}/ports/ | Replace ports by ID
[**UpdateK8sfilterByID**](K8sfilterApi.md#UpdateK8sfilterByID) | **Patch** /k8sfilter/{name}/ | Update k8sfilter by ID
[**UpdateK8sfilterListByID**](K8sfilterApi.md#UpdateK8sfilterListByID) | **Patch** /k8sfilter/ | Update k8sfilter by ID
[**UpdateK8sfilterLoglevelByID**](K8sfilterApi.md#UpdateK8sfilterLoglevelByID) | **Patch** /k8sfilter/{name}/loglevel/ | Update loglevel by ID
[**UpdateK8sfilterNodeportRangeByID**](K8sfilterApi.md#UpdateK8sfilterNodeportRangeByID) | **Patch** /k8sfilter/{name}/nodeport-range/ | Update nodeport-range by ID
[**UpdateK8sfilterPortsByID**](K8sfilterApi.md#UpdateK8sfilterPortsByID) | **Patch** /k8sfilter/{name}/ports/{ports_name}/ | Update ports by ID
[**UpdateK8sfilterPortsListByID**](K8sfilterApi.md#UpdateK8sfilterPortsListByID) | **Patch** /k8sfilter/{name}/ports/ | Update ports by ID
[**UpdateK8sfilterPortsPeerByID**](K8sfilterApi.md#UpdateK8sfilterPortsPeerByID) | **Patch** /k8sfilter/{name}/ports/{ports_name}/peer/ | Update peer by ID
[**UpdateK8sfilterSpanByID**](K8sfilterApi.md#UpdateK8sfilterSpanByID) | **Patch** /k8sfilter/{name}/span/ | Update span by ID
[**UpdateK8sfilterStartMorpheusByID**](K8sfilterApi.md#UpdateK8sfilterStartMorpheusByID) | **Patch** /k8sfilter/{name}/start-morpheus/ | Update start-morpheus by ID


# **CreateK8sfilterByID**
> CreateK8sfilterByID(ctx, name, k8sfilter)
Create k8sfilter by ID

Create operation of resource: k8sfilter

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8sfilter** | [**K8sfilter**](K8sfilter.md)| k8sfilterbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CreateK8sfilterPortsByID**
> CreateK8sfilterPortsByID(ctx, name, portsName, ports)
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

# **CreateK8sfilterPortsListByID**
> CreateK8sfilterPortsListByID(ctx, name, ports)
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

# **DeleteK8sfilterByID**
> DeleteK8sfilterByID(ctx, name)
Delete k8sfilter by ID

Delete operation of resource: k8sfilter

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

# **DeleteK8sfilterPortsByID**
> DeleteK8sfilterPortsByID(ctx, name, portsName)
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

# **DeleteK8sfilterPortsListByID**
> DeleteK8sfilterPortsListByID(ctx, name)
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

# **ReadK8sfilterByID**
> K8sfilter ReadK8sfilterByID(ctx, name)
Read k8sfilter by ID

Read operation of resource: k8sfilter

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 

### Return type

[**K8sfilter**](K8sfilter.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8sfilterDynOptByID**
> bool ReadK8sfilterDynOptByID(ctx, name)
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

# **ReadK8sfilterListByID**
> []K8sfilter ReadK8sfilterListByID(ctx, )
Read k8sfilter by ID

Read operation of resource: k8sfilter

### Required Parameters
This endpoint does not need any parameter.

### Return type

[**[]K8sfilter**](K8sfilter.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReadK8sfilterLoglevelByID**
> string ReadK8sfilterLoglevelByID(ctx, name)
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

# **ReadK8sfilterNodeportRangeByID**
> string ReadK8sfilterNodeportRangeByID(ctx, name)
Read nodeport-range by ID

Read operation of resource: nodeport-range

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

# **ReadK8sfilterPortsByID**
> Ports ReadK8sfilterPortsByID(ctx, name, portsName)
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

# **ReadK8sfilterPortsListByID**
> []Ports ReadK8sfilterPortsListByID(ctx, name)
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

# **ReadK8sfilterPortsPeerByID**
> string ReadK8sfilterPortsPeerByID(ctx, name, portsName)
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

# **ReadK8sfilterPortsStatusByID**
> string ReadK8sfilterPortsStatusByID(ctx, name, portsName)
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

# **ReadK8sfilterPortsTypeByID**
> string ReadK8sfilterPortsTypeByID(ctx, name, portsName)
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

# **ReadK8sfilterPortsUuidByID**
> string ReadK8sfilterPortsUuidByID(ctx, name, portsName)
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

# **ReadK8sfilterServiceNameByID**
> string ReadK8sfilterServiceNameByID(ctx, name)
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

# **ReadK8sfilterShadowByID**
> bool ReadK8sfilterShadowByID(ctx, name)
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

# **ReadK8sfilterSpanByID**
> bool ReadK8sfilterSpanByID(ctx, name)
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

# **ReadK8sfilterStartMorpheusByID**
> bool ReadK8sfilterStartMorpheusByID(ctx, name)
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

# **ReadK8sfilterTypeByID**
> string ReadK8sfilterTypeByID(ctx, name)
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

# **ReadK8sfilterUuidByID**
> string ReadK8sfilterUuidByID(ctx, name)
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

# **ReplaceK8sfilterByID**
> ReplaceK8sfilterByID(ctx, name, k8sfilter)
Replace k8sfilter by ID

Replace operation of resource: k8sfilter

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8sfilter** | [**K8sfilter**](K8sfilter.md)| k8sfilterbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ReplaceK8sfilterPortsByID**
> ReplaceK8sfilterPortsByID(ctx, name, portsName, ports)
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

# **ReplaceK8sfilterPortsListByID**
> ReplaceK8sfilterPortsListByID(ctx, name, ports)
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

# **UpdateK8sfilterByID**
> UpdateK8sfilterByID(ctx, name, k8sfilter)
Update k8sfilter by ID

Update operation of resource: k8sfilter

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **k8sfilter** | [**K8sfilter**](K8sfilter.md)| k8sfilterbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8sfilterListByID**
> UpdateK8sfilterListByID(ctx, k8sfilter)
Update k8sfilter by ID

Update operation of resource: k8sfilter

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **k8sfilter** | [**[]K8sfilter**](K8sfilter.md)| k8sfilterbody object | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8sfilterLoglevelByID**
> UpdateK8sfilterLoglevelByID(ctx, name, loglevel)
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

# **UpdateK8sfilterNodeportRangeByID**
> UpdateK8sfilterNodeportRangeByID(ctx, name, nodeportRange)
Update nodeport-range by ID

Update operation of resource: nodeport-range

### Required Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **ctx** | **context.Context** | context for authentication, logging, cancellation, deadlines, tracing, etc.
  **name** | **string**| ID of name | 
  **nodeportRange** | **string**| Port range used for NodePort services | 

### Return type

 (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UpdateK8sfilterPortsByID**
> UpdateK8sfilterPortsByID(ctx, name, portsName, ports)
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

# **UpdateK8sfilterPortsListByID**
> UpdateK8sfilterPortsListByID(ctx, name, ports)
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

# **UpdateK8sfilterPortsPeerByID**
> UpdateK8sfilterPortsPeerByID(ctx, name, portsName, peer)
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

# **UpdateK8sfilterSpanByID**
> UpdateK8sfilterSpanByID(ctx, name, span)
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

# **UpdateK8sfilterStartMorpheusByID**
> UpdateK8sfilterStartMorpheusByID(ctx, name, startMorpheus)
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

