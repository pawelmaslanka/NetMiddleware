set(TARGET_GRPC_FILES)
set(TARGET_GRPC_DIRS)

foreach (proto
        common interface lag port vlan)
    get_filename_component(proto_file "${CMAKE_CURRENT_SOURCE_DIR}/${proto}.proto" ABSOLUTE)
    get_filename_component(proto_file_path "${proto}" PATH)

    set(TARGET_DST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${proto}")
    file(MAKE_DIRECTORY ${TARGET_DST_DIR})

    set(proto_src "${TARGET_DST_DIR}/${proto}.pb.cc")
    set(proto_hdr "${TARGET_DST_DIR}/${proto}.pb.h")
    set(grpc_src "${TARGET_DST_DIR}/${proto}.grpc.pb.cc")
    set(grpc_hdr "${TARGET_DST_DIR}/${proto}.grpc.pb.h")

    set(TARGET "${proto_src}" "${proto_hdr}" "${grpc_src}" "${grpc_hdr}")
    add_custom_command(
            OUTPUT ${TARGET}
            COMMAND ${_PROTOBUF_PROTOC}
            ARGS --grpc_out ${TARGET_DST_DIR}
            --cpp_out ${TARGET_DST_DIR}
            -I "${TOP_PROTO_PATH}"
            --proto_path "${CMAKE_CURRENT_SOURCE_DIR}"
            --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
            ${proto_file}
            DEPENDS ${proto_file})

    list(APPEND TARGET_GRPC_FILES ${TARGET})
    list(APPEND TARGET_GRPC_DIRS ${TARGET_DST_DIR})
endforeach ()

# Include generated *.pb.h files
include_directories(${TARGET_GRPC_DIRS})

# Generate lib called libnet_grpc_proto.a
set(NET_GRPC_PROTO net_grpc_proto)
add_library(${NET_GRPC_PROTO}
        ${TARGET_GRPC_FILES})

# link_directories(/usr/lib/x86_64-linux-gnu)
target_link_libraries(${NET_GRPC_PROTO}
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

add_custom_command(TARGET ${NET_GRPC_PROTO} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${NET_GRPC_PROTO}> ${OUTPUT_DIR}
)
