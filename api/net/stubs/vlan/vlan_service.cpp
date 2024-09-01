#include "vlan_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status VlanService::CreateVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) {
    spdlog::info("Requested to create vlan instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status VlanService::DeleteVlan(grpc::ServerContext* context, const DPVlan::Vlan* request, DataPlane::Result* response) {
    spdlog::info("Requested to delete vlan instance '{}'", request->id());
    return grpc::Status::OK;
}
