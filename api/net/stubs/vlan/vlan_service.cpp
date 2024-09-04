#include "vlan_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status VlanService::CreateVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) {
    spdlog::info("Requested to create VLAN instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status VlanService::DeleteVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) {
    spdlog::info("Requested to delete VLAN instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status VlanService::AddVlanMember(grpc::ServerContext* context, const DPVlan::VlanMember* request, DataPlane::Result* response) {
    spdlog::info("Requested to add members '{}' to VLAN instance '{}' - type '{}'", request->members().Get(0).id(), request->vlan_id(), request->mode());
    return grpc::Status::OK;
}

grpc::Status VlanService::RemoveVlanMember(grpc::ServerContext* context, const DPVlan::VlanMember* request, DataPlane::Result* response) {
    spdlog::info("Requested to remove members '{}' from VLAN instance '{}' - type '{}'", request->members().Get(0).id(), request->vlan_id(), request->mode());
    return grpc::Status::OK;
}
