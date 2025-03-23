# Directory structure

The **config** directory include API to configure a **Data Plane** (ASIC, Linux, DPDK etc.). The **NetMiddleware** uses
this API as a client. This API is defined based on the *gRPC* (*protobuf*).
The **net** directory include interface to configure/control the **NetMiddleware** via the *JSON over HTTP*. The *
*NetMiddleware** uses this API as a server.
