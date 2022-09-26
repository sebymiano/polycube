# K8switch

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**Name** | **string** | Name of the k8switch service | [optional] [default to null]
**Uuid** | **string** | UUID of the Cube | [optional] [default to null]
**Type_** | **string** | Type of the Cube (TC, XDP_SKB, XDP_DRV) | [optional] [default to null]
**ServiceName** | **string** |  | [optional] [default to null]
**Loglevel** | **string** | Logging level of a cube, from none (OFF) to the most verbose (TRACE) | [optional] [default to null]
**DynOpt** | **bool** | Defines if the service should be automatically optimized by Morpheus | [optional] [default to null]
**StartMorpheus** | **bool** | Set this flag if you want to start Morpheus compiler | [optional] [default to null]
**Ports** | [**[]Ports**](Ports.md) | Entry of the ports table | [optional] [default to null]
**Shadow** | **bool** | Defines if the service is visible in Linux | [optional] [default to null]
**Span** | **bool** | Defines if all traffic is sent to Linux | [optional] [default to null]
**ClusterIpSubnet** | **string** | Range of VIPs where clusterIP services are exposed | [optional] [default to null]
**ClientSubnet** | **string** | Range of IPs of pods in this node | [optional] [default to null]
**VirtualClientSubnet** | **string** | Range where client&#39;s IPs are mapped into | [optional] [default to null]
**Service** | [**[]Service**](Service.md) | Services (i.e., virtual ip:protocol:port) exported to the client | [optional] [default to null]
**FwdTable** | [**[]FwdTable**](FwdTable.md) | Entry associated with the forwarding table | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


