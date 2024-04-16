cmake_minimum_required(VERSION 3.26.3)

project(NetRPC C CXX)

find_package(spdlog 1.11.0 REQUIRED)

include("${CMAKE_CURRENT_SOURCE_DIR}/common.cmake")

set(TOP_PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/protos")
set(COMMON_PROTO_PATH ${TOP_PROTO_PATH})

add_subdirectory(${COMMON_PROTO_PATH})

# Include generated *.pb.h files
include_directories(${COMMON_PROTO_PATH})

link_directories(${COMMON_PROTO_PATH})

foreach(_target
    service)
    add_executable(${_target} "lag/lag_service.cpp" service.cpp)
    target_link_libraries(${_target}
        PRIVATE spdlog::spdlog_header_only
        net_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
endforeach()
