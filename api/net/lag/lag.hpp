#pragma once

#include "lag.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

class LagService final : public Net::Lag::Service {
public:
    virtual ~LagService() = default;
    virtual grpc::Status Create(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) override;
    virtual grpc::Status Delete(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) override;
    virtual grpc::Status AddMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) override;
    virtual grpc::Status RemoveMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) override;
};

int main(void) {
    LagService lagService;
    return 0;
}
