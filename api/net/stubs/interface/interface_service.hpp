#pragma once

#include "interface.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

namespace DPIface = DataPlane::Interface;

class InterfaceService final : public DPIface::InterfaceManagement::Service {
public:
    virtual ~InterfaceService() = default;
    virtual grpc::Status CreateInterface(grpc::ServerContext* context, const DPIface::Iface* request, DataPlane::Result* response) override;
    virtual grpc::Status DeleteInterface(grpc::ServerContext* context, const DPIface::Iface* request, DataPlane::Result* response) override;
    virtual grpc::Status SetAdminState(grpc::ServerContext* context, const DPIface::IfaceState* request, DataPlane::Result* response) override;
    virtual grpc::Status SetSpeed(grpc::ServerContext* context, const DPIface::IfaceSpeed* request, DataPlane::Result* response) override;
};
