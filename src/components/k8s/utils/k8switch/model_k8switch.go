/*
 * k8switch API
 *
 * k8switch API generated from k8switch.yang
 *
 * API version: 1.0.0
 * Generated by: Swagger Codegen (https://github.com/swagger-api/swagger-codegen.git)
 */

package swagger

type K8switch struct {
	// Name of the k8switch service
	Name string `json:"name,omitempty"`
	// UUID of the Cube
	Uuid string `json:"uuid,omitempty"`
	// Type of the Cube (TC, XDP_SKB, XDP_DRV)
	Type_ string `json:"type,omitempty"`
	ServiceName string `json:"service-name,omitempty"`
	// Logging level of a cube, from none (OFF) to the most verbose (TRACE)
	Loglevel string `json:"loglevel,omitempty"`
	// Defines if the service should be automatically optimized by Morpheus
	DynOpt bool `json:"dyn-opt,omitempty"`
	// Set this flag if you want to start Morpheus compiler
	StartMorpheus bool `json:"start-morpheus,omitempty"`
	// Entry of the ports table
	Ports []Ports `json:"ports,omitempty"`
	// Defines if the service is visible in Linux
	Shadow bool `json:"shadow,omitempty"`
	// Defines if all traffic is sent to Linux
	Span bool `json:"span,omitempty"`
	// Range of VIPs where clusterIP services are exposed
	ClusterIpSubnet string `json:"cluster-ip-subnet,omitempty"`
	// Range of IPs of pods in this node
	ClientSubnet string `json:"client-subnet,omitempty"`
	// Range where client's IPs are mapped into
	VirtualClientSubnet string `json:"virtual-client-subnet,omitempty"`
	// Services (i.e., virtual ip:protocol:port) exported to the client
	Service []Service `json:"service,omitempty"`
	// Entry associated with the forwarding table
	FwdTable []FwdTable `json:"fwd-table,omitempty"`
}