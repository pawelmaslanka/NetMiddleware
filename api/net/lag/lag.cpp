#include "lag.hpp"

// #include <spdlog/spdlog.h>

grpc::Status LagService::Create(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) {
    // spdlog::info("Requested to create LAG instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status LagService::Delete(grpc::ServerContext* context, const Net::LagIface* request, Net::Result* response) {
    // spdlog::info("Requested to delete LAG instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status LagService::AddMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) {
    // spdlog::info("Requested to add members '{}' to LAG instance '{}'", request->members().size(), request->lagid());
    return grpc::Status::OK;
}

grpc::Status LagService::RemoveMember(grpc::ServerContext* context, const Net::LagMember* request, Net::Result* response) {
    // spdlog::info("Requested to remove members '{}' from LAG instance '{}'", request->members().size(), request->lagid());
    return grpc::Status::OK;
}
