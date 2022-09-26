# Firewall

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Name** | **string** | Name of the firewall service | [optional] [default to null]
**Uuid** | **string** | UUID of the Cube | [optional] [default to null]
**Type_** | **string** | Type of the Cube (TC, XDP_SKB, XDP_DRV) | [optional] [default to null]
**ServiceName** | **string** |  | [optional] [default to null]
**Loglevel** | **string** | Logging level of a cube, from none (OFF) to the most verbose (TRACE) | [optional] [default to null]
**DynOpt** | **bool** | Defines if the service should be automatically optimized by Morpheus | [optional] [default to null]
**StartMorpheus** | **bool** | Set this flag if you want to start Morpheus compiler | [optional] [default to null]
**Conntrack** | **string** | Enables the Connection Tracking module. Mandatory if connection tracking rules are needed. Default is ON. | [optional] [default to null]
**AcceptEstablished** | **string** | If Connection Tracking is enabled, all packets belonging to ESTABLISHED connections will be accepted automatically. Default is ON. | [optional] [default to null]
**SessionTable** | [**[]SessionTable**](SessionTable.md) |  | [optional] [default to null]
**Chain** | [**[]Chain**](Chain.md) |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


