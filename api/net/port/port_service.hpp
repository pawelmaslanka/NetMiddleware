#pragma once

#include "port.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

class PortService final : public DataPlane::PortManagement::Service {
public:
    virtual ~PortService() = default;
    virtual grpc::Status CreatePort(grpc::ServerContext* context, const ::DataPlane::Port* request, ::DataPlane::Result* response) override;
    virtual grpc::Status DeletePort(grpc::ServerContext* context, const ::DataPlane::Port* request, ::DataPlane::Result* response) override;
    virtual grpc::Status SetPortBreakout(grpc::ServerContext* context, const ::DataPlane::PortBreakoutMode* request, ::DataPlane::Result* response) override;
};
