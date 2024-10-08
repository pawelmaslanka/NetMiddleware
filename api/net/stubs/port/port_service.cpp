#include "port_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status PortService::CreatePort(grpc::ServerContext* context, const DPPort::Port* request, DataPlane::Result* response) {
    spdlog::info("Requested to create port instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status PortService::DeletePort(grpc::ServerContext* context, const DPPort::Port* request, DataPlane::Result* response) {
    spdlog::info("Requested to delete port instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status PortService::SetPortBreakout(grpc::ServerContext* context, const DPPort::PortBreakoutMode* request, DataPlane::Result* response) {
    spdlog::info("Requested to set port breakout mode '{}'", request->port().id());
    return grpc::Status::OK;
}
