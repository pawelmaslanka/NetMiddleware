#pragma once

#include "port.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

class PortService final : public Net::PortManagement::Service {
public:
    virtual ~PortService() = default;
    virtual grpc::Status CreatePort(grpc::ServerContext* context, const ::Net::Port* request, ::Net::Result* response) override;
    virtual grpc::Status DeletePort(grpc::ServerContext* context, const ::Net::Port* request, ::Net::Result* response) override;
    virtual grpc::Status SetPortBreakout(grpc::ServerContext* context, const ::Net::PortBreakoutMode* request, ::Net::Result* response) override;
};
