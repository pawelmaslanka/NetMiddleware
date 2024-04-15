cmake_minimum_required(VERSION 3.8)

project(NetRPC C CXX)

include(./common.cmake)

# Proto file
get_filename_component(net_proto "./protos/lag.proto" ABSOLUTE)
get_filename_component(net_proto_path "${net_proto}" PATH)

# Generated sources
set(net_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/../../protos/lag.pb.cc")
set(net_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../../protos/lag.pb.h")
set(net_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/../../protos/lag.grpc.pb.cc")
set(net_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../../protos/lag.grpc.pb.h")
add_custom_command(
      OUTPUT "${net_proto_srcs}" "${net_proto_hdrs}" "${net_grpc_srcs}" "${net_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/../../protos"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/../../protos"
        -I "${net_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${net_proto}"
      DEPENDS "${net_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../protos")

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

# configure_file(net_grpc_proto "${CMAKE_CURRENT_BINARY_DIR}/../../protos" COPYONLY)
# file(COPY "${CMAKE_CURRENT_BINARY_DIR}/net_grpc_proto"
#      DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../protos")

# install(TARGETS net_grpc_proto
#         ARCHIVE DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/../../protos")

add_custom_command(TARGET net_grpc_proto POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:net_grpc_proto> "${CMAKE_CURRENT_BINARY_DIR}/../../protos"
)

foreach(_target
  lag)
  add_executable(${_target} "lag/${_target}.cpp")
  target_link_libraries(${_target}
    net_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()
