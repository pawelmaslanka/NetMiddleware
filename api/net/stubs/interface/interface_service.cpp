#include "interface_service.hpp"

#include <spdlog/spdlog.h>

grpc::Status InterfaceService::CreateInterface(grpc::ServerContext* context, const DPIface::Iface* request, DataPlane::Result* response) {
    spdlog::info("Requested to create interface instance '{}' with MAC address '{}'", request->id(), request->mac_address());
    return grpc::Status::OK;
}

grpc::Status InterfaceService::DeleteInterface(grpc::ServerContext* context, const DPIface::Iface* request, DataPlane::Result* response) {
    spdlog::info("Requested to delete interface instance '{}'", request->id());
    return grpc::Status::OK;
}

grpc::Status InterfaceService::SetAdminState(grpc::ServerContext* context, const DPIface::IfaceState* request, DataPlane::Result* response) {
    spdlog::info("Requested to set administratively state '{}' on the interface '{}'", request->state(), request->iface().id());
    return grpc::Status::OK;
}

grpc::Status InterfaceService::SetSpeed(grpc::ServerContext* context, const DPIface::IfaceSpeed* request, DataPlane::Result* response) {
    spdlog::info("Requested to set speed '{}' on the interface '{}'", request->speed(), request->iface().id());
    return grpc::Status::OK;
}
