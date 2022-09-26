# K8sfilter

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Name** | **string** | Name of the k8sfilter service | [optional] [default to null]
**Uuid** | **string** | UUID of the Cube | [optional] [default to null]
**Type_** | **string** | Type of the Cube (TC, XDP_SKB, XDP_DRV) | [optional] [default to null]
**ServiceName** | **string** |  | [optional] [default to null]
**Loglevel** | **string** | Logging level of a cube, from none (OFF) to the most verbose (TRACE) | [optional] [default to null]
**DynOpt** | **bool** | Defines if the service should be automatically optimized by Morpheus | [optional] [default to null]
**StartMorpheus** | **bool** | Set this flag if you want to start Morpheus compiler | [optional] [default to null]
**Ports** | [**[]Ports**](Ports.md) | Entry of the ports table | [optional] [default to null]
**Shadow** | **bool** | Defines if the service is visible in Linux | [optional] [default to null]
**Span** | **bool** | Defines if all traffic is sent to Linux | [optional] [default to null]
**NodeportRange** | **string** | Port range used for NodePort services | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


