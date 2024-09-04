#pragma once

#include "vlan.grpc.pb.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

namespace DPVlan = DataPlane::Vlan;

class VlanService final : public DPVlan::VlanManagement::Service {
public:
    virtual ~VlanService() = default;
    virtual grpc::Status CreateVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) override;
    virtual grpc::Status DeleteVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) override;
    virtual grpc::Status AddVlanMember(grpc::ServerContext* context, const DPVlan::VlanMember* request, DataPlane::Result* response) override;
    virtual grpc::Status RemoveVlanMember(grpc::ServerContext* context, const DPVlan::VlanMember* request, DataPlane::Result* response) override;
};
