#pragma once

#include "lag.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

namespace DPLag = DataPlane::Lag;

class LagService final : public DPLag::LagManagement::Service {
public:
    virtual ~LagService() = default;
    virtual grpc::Status CreateLag(grpc::ServerContext* context, const DPLag::Lag* request, DataPlane::Result* response) override;
    virtual grpc::Status DeleteLag(grpc::ServerContext* context, const DPLag::Lag* request, DataPlane::Result* response) override;
    virtual grpc::Status AddLagMember(grpc::ServerContext* context, const DPLag::LagMember* request, DataPlane::Result* response) override;
    virtual grpc::Status RemoveLagMember(grpc::ServerContext* context, const DPLag::LagMember* request, DataPlane::Result* response) override;
};
