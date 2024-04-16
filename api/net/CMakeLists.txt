cmake_minimum_required(VERSION 3.26.3)

project(NetRPC C CXX)

find_package(spdlog 1.11.0 REQUIRED)

include(./common.cmake)

set(LAG_PROTO_PATH protos/lag)

# Proto file
get_filename_component(net_proto "./${LAG_PROTO_PATH}/lag.proto" ABSOLUTE)
get_filename_component(net_proto_path "${net_proto}" PATH)

# Generated sources
set(net_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}/lag.pb.cc")
set(net_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}/lag.pb.h")
set(net_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}/lag.grpc.pb.cc")
set(net_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}/lag.grpc.pb.h")
add_custom_command(
      OUTPUT "${net_proto_srcs}" "${net_proto_hdrs}" "${net_grpc_srcs}" "${net_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}"
        -I "${net_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${net_proto}"
      DEPENDS "${net_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}")

# net_grpc_proto
add_library(net_grpc_proto
  ${net_grpc_srcs}
  ${net_grpc_hdrs}
  ${net_proto_srcs}
  ${net_proto_hdrs})
target_link_libraries(net_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

add_custom_command(TARGET net_grpc_proto POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:net_grpc_proto> "${CMAKE_CURRENT_BINARY_DIR}/../../${LAG_PROTO_PATH}"
)

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
