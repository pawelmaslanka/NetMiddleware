#include <nlohmann/json.hpp> // Must be at top due to conflicting with Array from std_types.hpp
#include "interface_management.hpp"
#include "lag_management.hpp"
#include "port_management.hpp"
#include "vlan_management.hpp"

#include "northbound_api.hpp"

#include "module_names.hpp"
#include "module_registry.hpp"

#include "request_handle/request_handle.hpp"
#include "request_handle/interface/aggregate_ethernet/aggregate_ethernet_request_handle.hpp"
#include "request_handle/interface/ethernet/ethernet_request_handle.hpp"
#include "request_handle/platform/port/port_request_handle.hpp"
#include "request_handle/protocol/lacp/lacp_request_handle.hpp"
#include "request_handle/protocol/rstp/rstp_request_handle.hpp"
#include "request_handle/vlan/vlan_request_handle.hpp"

#include <lib/log.hpp>
#include <xpath/xpath.hpp>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <cstdlib>

#include <grpcpp/grpcpp.h>

using Json = nlohmann::json;

namespace Net = Lib::Net;

int main(const int argc, const char* argv[]) {
    auto console_sink = MakeShared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::trace);
    console_sink->set_pattern("%+");

    auto file_sink = MakeShared<spdlog::sinks::basic_file_sink_mt>("/tmp/netmiddleware.log", true);
    file_sink->set_level(spdlog::level::trace);
    file_sink->set_pattern("%+");

    auto logger_registry = MakeShared<Log::LoggerRegistry>(spdlog::sinks_init_list{ console_sink, file_sink });
    logger_registry->registerModule(Module::Name::IFACE_MANAGER);
    logger_registry->getLogger(Module::Name::IFACE_MANAGER)->set_level(spdlog::level::info);
    logger_registry->registerModule(Module::Name::LAG_MANAGER);
    logger_registry->getLogger(Module::Name::LAG_MANAGER)->set_level(spdlog::level::info);
    logger_registry->registerModule(Module::Name::PORT_MANAGER);
    logger_registry->getLogger(Module::Name::PORT_MANAGER)->set_level(spdlog::level::info);
    logger_registry->registerModule(Module::Name::VLAN_MANAGER);
    logger_registry->getLogger(Module::Name::VLAN_MANAGER)->set_level(spdlog::level::info);
    logger_registry->registerModule(Module::Name::REQUEST_HANDLE);
    logger_registry->getLogger(Module::Name::REQUEST_HANDLE)->set_level(spdlog::level::info);

    auto module_registry = MakeShared<ModuleRegistry>();
    module_registry->setLoggerRegistry(logger_registry);
    auto rpc_net_channel = grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials());
    auto intf_mngr = MakeShared<InterfaceManager>(Module::Name::IFACE_MANAGER, module_registry, rpc_net_channel);
    auto lag_mngr = MakeShared<LagManager>(Module::Name::LAG_MANAGER, module_registry, rpc_net_channel);
    auto port_mngr = MakeShared<PortManager>(Module::Name::PORT_MANAGER, module_registry, rpc_net_channel);
    auto vlan_mngr = MakeShared<VlanManager>(Module::Name::VLAN_MANAGER, module_registry, rpc_net_channel);
    module_registry->setInterfaceModule(intf_mngr);
    module_registry->setLagModule(lag_mngr);
    module_registry->setPortModule(port_mngr);
    module_registry->setVlanModule(vlan_mngr);

    spdlog::info("Subscribe VLAN manager to LAG manager");
    lag_mngr->subscribe(vlan_mngr);

    spdlog::info("Successfully passed test");
    auto root_req_hdl = MakeShared<RequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, XPath::ROOT_NODE_START);
    auto interface_req_hdl = MakeShared<RequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, "interface");
    root_req_hdl->add(interface_req_hdl);
    auto agg_ethernet_req_hdl = MakeShared<AggregateEthernetRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, interface_req_hdl);
    interface_req_hdl->add(agg_ethernet_req_hdl);
    auto ethernet_req_hdl = MakeShared<EthernetRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, interface_req_hdl);
    interface_req_hdl->add(ethernet_req_hdl);
    auto platform_req_hdl = MakeShared<RequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, "platform");
    root_req_hdl->add(platform_req_hdl);
    auto platform_port_req_hdl = MakeShared<PortRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry);
    platform_req_hdl->add(platform_port_req_hdl);
    auto protocol_req_hdl = MakeShared<RequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, "protocol");
    root_req_hdl->add(protocol_req_hdl);
    auto lacp_req_hdl = MakeShared<LacpRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, protocol_req_hdl);
    protocol_req_hdl->add(lacp_req_hdl);
    auto rstp_req_hdl = MakeShared<RstpRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, protocol_req_hdl);
    protocol_req_hdl->add(rstp_req_hdl);
    auto vlan_req_hdl = MakeShared<VlanRequestHandle>(Module::Name::REQUEST_HANDLE, module_registry, root_req_hdl);
    root_req_hdl->add(vlan_req_hdl);
    ConnectionManagement::Server cm;
    cm.addOnPostConnectionHandler("config_running_update", [&module_registry, &root_req_hdl](const String& path, String data_request, String& return_data) {
        if (path != ConnectionManagement::URIRequestPath::Config::CONFIG_UPDATE) {
            spdlog::debug("Unexpected URI requested '{}' - expected '{}'", path, ConnectionManagement::URIRequestPath::Config::CONFIG_UPDATE);
            return HTTP::StatusCode::INTERNAL_SUCCESS;
        }

        spdlog::info("Get request on {} with POST method: {}", path, data_request);

        auto request = Json::parse(data_request);
        IRequestHandle::Request req(request);
        IRequestHandle::Response res;
        if (!root_req_hdl->handle(req, res)) {
            spdlog::error("Failed to handle request: '{}'", res.Data.Data);
            // TODO: Put the Json::parse(res.Data) to server response
            return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
        }

        return HTTP::StatusCode::OK;

        auto op = request["op"].get<String>();
        Vector<String> xpath_tokens;
        // Returns first token
        auto xpath = request["path"].get<String>();
        spdlog::info("Parse '{}'", xpath);
        char* token = std::strtok(const_cast<char*>(xpath.c_str()), "/");
        // Keep printing tokens while one of the
        // delimiters present in str[].
        while (token != nullptr) {
            xpath_tokens.push_back(token);
            token = std::strtok(nullptr, "/");
        }

        if (xpath_tokens.size() == 0) {
            spdlog::warn("The xpath '{}' required at least two nodes", xpath);
            return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
        }

        spdlog::warn("Unsupported xpath '{}'", xpath);
        return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
    });

    spdlog::info("Listening on connection from client...");
    if (!cm.run("127.0.0.1", 8000)) {
        spdlog::error("Failed to run connection management server");
        ::exit(EXIT_FAILURE);
    }

    #include <iostream>
    std::cin.get();
    ::exit(EXIT_SUCCESS);
}
