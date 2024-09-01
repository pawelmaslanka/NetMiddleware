#include "lag_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status LagService::CreateLag(grpc::ServerContext* context, const DPLag::Lag* request, DataPlane::Result* response) {
    spdlog::info("Requested to create LAG instance '{}' with MAC address '{}'", request->id(), request->mac_address());
    return grpc::Status::OK;
}

grpc::Status LagService::DeleteLag(grpc::ServerContext* context, const DPLag::Lag* request, DataPlane::Result* response) {
    spdlog::info("Requested to delete LAG instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status LagService::AddLagMember(grpc::ServerContext* context, const DPLag::LagMember* request, DataPlane::Result* response) {
    spdlog::info("Requested to add members '{}' to LAG instance '{}'", request->members().Get(0).id(), request->lag_id());
    return grpc::Status::OK;
}

grpc::Status LagService::RemoveLagMember(grpc::ServerContext* context, const DPLag::LagMember* request, DataPlane::Result* response) {
    spdlog::info("Requested to remove members '{}' from LAG instance '{}'", request->members().Get(0).id(), request->lag_id());
    return grpc::Status::OK;
}
