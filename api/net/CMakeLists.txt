cmake_minimum_required(VERSION 3.26.3)

project(NetRPC C CXX)

find_package(spdlog 1.11.0 REQUIRED)

include("${CMAKE_CURRENT_SOURCE_DIR}/common.cmake")

set(LIB_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TOP_PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/proto")

add_subdirectory(${TOP_PROTO_PATH})

# Include generated *.pb.h files
include_directories("${TOP_PROTO_PATH}/common" "${TOP_PROTO_PATH}/interface" "${TOP_PROTO_PATH}/lag" "${TOP_PROTO_PATH}/vlan")

link_directories(${LIB_OUTPUT_DIR})

set(BINARY_OUTPUT "Service")
add_executable(${BINARY_OUTPUT} "lag/lag_service.cpp" test_service.cpp)
target_link_libraries(${BINARY_OUTPUT}
    PRIVATE spdlog::spdlog_header_only
    net_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
