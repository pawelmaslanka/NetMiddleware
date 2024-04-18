#include "lag/lag_service.hpp"

#include <spdlog/spdlog.h>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "lag.grpc.pb.h"

#include <sstream>

void RunServer(uint16_t port) {
    std::ostringstream stringStream;
    stringStream << "127.0.0.1:";
    stringStream << port;
    std::string server_address = stringStream.str();
    LagService lagService;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&lagService);
    // Finally assemble the server.
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    spdlog::info("Server listening on {}", server_address);

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char* argv[]) {
    RunServer(50052);
    return 0;
}
