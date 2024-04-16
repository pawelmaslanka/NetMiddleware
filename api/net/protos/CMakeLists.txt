set(TOP_PROTO_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")

# Proto file
get_filename_component(common_proto "${CMAKE_CURRENT_SOURCE_DIR}/common.proto" ABSOLUTE)
get_filename_component(common_proto_path "${common_proto}" PATH)

get_filename_component(lag_proto "${CMAKE_CURRENT_SOURCE_DIR}/lag.proto" ABSOLUTE)
get_filename_component(lag_proto_path "${lag_proto}" PATH)

get_filename_component(port_proto "${CMAKE_CURRENT_SOURCE_DIR}/port.proto" ABSOLUTE)
get_filename_component(port_proto_path "${port_proto}" PATH)

# Generated sources
set(lag_proto_src "${CMAKE_CURRENT_SOURCE_DIR}/lag.pb.cc")
set(lag_proto_hdr "${CMAKE_CURRENT_SOURCE_DIR}/lag.pb.h")
set(lag_grpc_src "${CMAKE_CURRENT_SOURCE_DIR}/lag.grpc.pb.cc")
set(lag_grpc_hdr "${CMAKE_CURRENT_SOURCE_DIR}/lag.grpc.pb.h")

set(port_proto_src "${CMAKE_CURRENT_SOURCE_DIR}/port.pb.cc")
set(port_proto_hdr "${CMAKE_CURRENT_SOURCE_DIR}/port.pb.h")
set(port_grpc_src "${CMAKE_CURRENT_SOURCE_DIR}/port.grpc.pb.cc")
set(port_grpc_hdr "${CMAKE_CURRENT_SOURCE_DIR}/port.grpc.pb.h")

set(common_proto_src "${CMAKE_CURRENT_SOURCE_DIR}/common.pb.cc")
set(common_proto_hdr "${CMAKE_CURRENT_SOURCE_DIR}/common.pb.h")

set(PROTOC_OUTPUT_LIST
    "${lag_proto_src}"
    "${lag_proto_hdr}"
    "${lag_grpc_src}"
    "${lag_grpc_hdr}"
    "${port_proto_src}"
    "${port_proto_hdr}"
    "${port_grpc_src}"
    "${port_grpc_hdr}"
    "${common_proto_src}"
    "${common_proto_hdr}")

set(PROTO_FILES_LIST
    "${common_proto}"
    "${lag_proto}"
    "${port_proto}")

add_custom_command(
    OUTPUT ${PROTOC_OUTPUT_LIST}
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}"
        -I "${TOP_PROTO_PATH}"
        --proto_path "${CMAKE_CURRENT_SOURCE_DIR}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        ${PROTO_FILES_LIST}
    DEPENDS ${PROTO_FILES_LIST})

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

set(NET_GRPC_PROTO net_grpc_proto)

# net_grpc_proto
add_library(${NET_GRPC_PROTO}
    ${lag_grpc_src}
    ${lag_grpc_hdr}
    ${lag_proto_src}
    ${lag_proto_hdr}
    ${port_proto_src}
    ${port_proto_hdr}
    ${common_proto_src}
    ${common_proto_hdr})
target_link_libraries(${NET_GRPC_PROTO}
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})

add_custom_command(TARGET ${NET_GRPC_PROTO} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${NET_GRPC_PROTO}> "${CMAKE_CURRENT_SOURCE_DIR}"
)
