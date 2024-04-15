cmake_minimum_required(VERSION 3.26.3)

project(NetMiddleware LANGUAGES CXX)

find_package(fmt 9.1.0 REQUIRED)
# Seeking lib as seen in /usr/local/lib/cmake/nlohmann_json_schema_validator
find_package(nlohmann_json_schema_validator 2.2.0 REQUIRED)
find_package(nlohmann_json 3.11.3 REQUIRED)
find_package(spdlog 1.11.0 REQUIRED)

include(./api/net/common.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR src)

include_directories(
    ${SRC_DIR}
    ${SRC_DIR}/lib
    api/net
)

set(CPP_HEADER_EXT hpp)
set(CPP_SRC_EXT cpp)

set(INC_LIST
    "${SRC_DIR}/lib/observer.${CPP_HEADER_EXT}"
    "${SRC_DIR}/lib/lag_observable.${CPP_HEADER_EXT}"
    "${SRC_DIR}/lib/lag_queryable.${CPP_HEADER_EXT}"
)

set(SRC_LIST
    "${SRC_DIR}/lib/observer.${CPP_SRC_EXT}"
    "${SRC_DIR}/lib/lag_observable.${CPP_SRC_EXT}"
    "${SRC_DIR}/interface_management.${CPP_SRC_EXT}"
    "${SRC_DIR}/lag_management.${CPP_SRC_EXT}"
    "${SRC_DIR}/port_management.${CPP_SRC_EXT}"
    "${SRC_DIR}/vlan_management.${CPP_SRC_EXT}"
)

# add_library(net_grpc_proto STATIC IMPORTED) # or STATIC instead of SHARED
# set_target_properties(net_grpc_proto PROPERTIES
#   IMPORTED_LOCATION "api/net/protos/libnet_grpc_proto.a"
# )

link_directories(api/net/protos)

add_executable(${PROJECT_NAME} ${INC_LIST} ${SRC_LIST} main.${CPP_SRC_EXT})
target_link_libraries(${PROJECT_NAME}
    PRIVATE nlohmann_json::nlohmann_json spdlog::spdlog_header_only
    net_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF})