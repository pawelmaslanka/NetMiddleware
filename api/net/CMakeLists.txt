cmake_minimum_required(VERSION 3.18.4)

project(NetRPC C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt 7.1.3 REQUIRED)
find_package(nlohmann_json 3.9.1 REQUIRED)
find_package(spdlog 1.8.1 REQUIRED)

find_package(Threads REQUIRED)

set(LIST_LINK_DIRS "${OUTPUT_DIR}")

if(APPLE)
    # NOTE: The file "common.cmake" has been taken from
    # the official gRPC repo: https://github.com/grpc/grpc
    include(common.cmake)
else()
    # SONiC 202305
    set(_PROTOBUF_PROTOC /usr/bin/protoc)
    set(_PROTOBUF_LIBPROTOBUF protobuf)
    set(_GRPC_CPP_PLUGIN_EXECUTABLE /usr/bin/grpc_cpp_plugin)
    set(_GRPC_GRPCPP grpc++)
    set(_REFLECTION grpc++_reflection)
    list(APPEND LIST_LINK_DIRS "/usr/lib/x86_64-linux-gnu")
endif()

set(TOP_PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/proto")

add_subdirectory(${TOP_PROTO_PATH})

# Include generated *.pb.h files
include_directories(
    "${TOP_PROTO_PATH}/common"
    "${TOP_PROTO_PATH}/interface"
    "${TOP_PROTO_PATH}/lag"
    "${TOP_PROTO_PATH}/port"
    "${TOP_PROTO_PATH}/vlan")

link_directories(${LIST_LINK_DIRS})

set(BINARY_OUTPUT_NAME "TestService")
include_directories(stubs/)
add_executable(${BINARY_OUTPUT_NAME} "stubs/interface/interface_service.cpp" "stubs/lag/lag_service.cpp" "stubs/port/port_service.cpp" "stubs/vlan/vlan_service.cpp" test_service.cpp)
target_link_libraries(${BINARY_OUTPUT_NAME}
    PRIVATE spdlog::spdlog_header_only
    net_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})

add_custom_command(TARGET ${BINARY_OUTPUT_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${BINARY_OUTPUT_NAME}> ${OUTPUT_DIR})
