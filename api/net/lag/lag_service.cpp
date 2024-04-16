#include "lag_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status LagService::CreateLag(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) {
    spdlog::info("Requested to create LAG instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status LagService::DeleteLag(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) {
    spdlog::info("Requested to delete LAG instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status LagService::AddLagMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) {
    spdlog::info("Requested to add members '{}' to LAG instance '{}'", request->members().size(), request->lag_iface().id());
    return grpc::Status::OK;
}

grpc::Status LagService::RemoveLagMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) {
    spdlog::info("Requested to remove members '{}' from LAG instance '{}'", request->members().size(), request->lag_iface().id());
    return grpc::Status::OK;
}
