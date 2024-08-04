#include <nlohmann/json.hpp> // Must be at top due to conflicting with Array from std_types.hpp
#include "interface_management.hpp"
#include "lag_management.hpp"
#include "port_management.hpp"
#include "vlan_management.hpp"

#include "northbound_api.hpp"

#include "module_names.hpp"
#include "module_registry.hpp"

// #include "lib/log_management.hpp"
#include <lib/log.hpp>

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

    auto module_registry = MakeShared<ModuleRegistry>();
    module_registry->setLoggerRegistry(logger_registry);
    auto rpc_net_channel = grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials());
    auto intf_mngr = MakeShared<InterfaceManager>(Module::Name::IFACE_MANAGER, module_registry, rpc_net_channel);
    auto lag_mngr = MakeShared<LagManager>(Module::Name::LAG_MANAGER, module_registry, rpc_net_channel);
    auto port_mngr = MakeShared<PortManager>(Module::Name::PORT_MANAGER, module_registry, rpc_net_channel);
    auto vlan_mngr = MakeShared<VlanManager>(Module::Name::VLAN_MANAGER, module_registry);
    module_registry->setInterfaceModule(intf_mngr);
    module_registry->setLagModule(lag_mngr);
    module_registry->setPortModule(port_mngr);
    module_registry->setVlanModule(vlan_mngr);

    // TEST: BEG

    spdlog::info("Subscribe VLAN manager to LAG manager");
    lag_mngr->subscribe(vlan_mngr);

    // if (!vlan_mngr->removeTaggedMember(vid2, lag1_id)) {
    //     spdlog::error("Failed to remove tagged member '{}' to VLAN '{}'", lag1_id, vid2);
    //     ::exit(EXIT_FAILURE);
    // }

    // if (!vlan_mngr->deleteVlan(vid2)) {
    //     spdlog::error("Failed to delete VLAN '{}'", vid2);
    //     ::exit(EXIT_FAILURE);
    // }

    // if (!lag_mngr->removeMember(lag1_id, eth1_1_id)) {
    //     spdlog::error("Failed to remove member '{}' from LAG '{}'", eth1_1_id);
    //     ::exit(EXIT_FAILURE);
    // }

    // if (!lag_mngr->deleteLag(lag1_id)) {
    //     spdlog::error("Failed to delete LAG '{}'", lag1_id);
    //     ::exit(EXIT_FAILURE);
    // }

    spdlog::info("Successfully passed test");
    ConnectionManagement::Server cm;
    cm.addOnPostConnectionHandler("config_running_update", [&module_registry](const String& path, String data_request, String& return_data) {
        if (path != ConnectionManagement::URIRequestPath::Config::CONFIG_UPDATE) {
            spdlog::debug("Unexpected URI requested '{}' - expected '{}'", path, ConnectionManagement::URIRequestPath::Config::CONFIG_UPDATE);
            return HTTP::StatusCode::INTERNAL_SUCCESS;
        }

        spdlog::info("Get request on {} with POST method: {}", path, data_request);

        auto request = Json::parse(data_request);
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
        
        // FIXME: Implement the chain of responsibility design pattern
        if (xpath_tokens[0] == "interface") {
            if (xpath_tokens.size() > 1) {
                if (xpath_tokens[1] == "aggregate-ethernet") {
                    if (xpath_tokens.size() == 2) {
                        if (op == "add") {
                            auto lag_id = request["value"].get<String>();
                            if (!std::dynamic_pointer_cast<LagManager>(module_registry->lagModule())->createLag(lag_id)) {
                                spdlog::error("Failed to create LAG '{}'", lag_id);
                                return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                            }

                            return HTTP::StatusCode::OK;
                        }
                    }
                    if (xpath_tokens.size() == 4) {
                        auto lag_id = xpath_tokens[2];
                        if (xpath_tokens[3] == "members") {
                            if (op == "add") {
                                auto iface_id = request["value"].get<String>();
                                if (!std::dynamic_pointer_cast<LagManager>(module_registry->lagModule())->addMember(lag_id, iface_id)) {
                                    spdlog::error("Failed to add member '{}' to LAG '{}'", iface_id, lag_id);
                                    return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                                }

                                return HTTP::StatusCode::OK;
                            }
                        }
                    }
                }
                else if (xpath_tokens[1] == "ethernet") {
                    if (xpath_tokens.size() == 2) {
                        if (op == "add") {
                            auto iface_id = request["value"].get<String>();
                            if (!std::dynamic_pointer_cast<InterfaceManager>(module_registry->interfaceModule())->createInterface(iface_id)) {
                                spdlog::error("Failed to create the interface '{}'", iface_id);
                                return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                            }

                            return HTTP::StatusCode::OK;
                        }
                    }
                    else if (xpath_tokens.size() == 4) {
                        if (op == "add") {
                            auto iface_id = xpath_tokens[2];
                            if (xpath_tokens[3] == "speed") {
                                auto speed_str = request["value"].get<String>();
                                auto speed = Net::Interface::LinkSpeed::SPEED_MAX;
                                if (speed_str == "400G") {
                                    speed = Net::Interface::LinkSpeed::SPEED_400G;
                                }
                                else if (speed_str == "100G") {
                                    speed = Net::Interface::LinkSpeed::SPEED_100G;
                                }

                                if (!std::dynamic_pointer_cast<InterfaceManager>(module_registry->interfaceModule())->setSpeed(iface_id, speed)) {
                                    spdlog::error("Failed to set speed '{}' on the interface '{}'", speed_str, iface_id);
                                    return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                                }

                                return HTTP::StatusCode::OK;
                            }
                            else if (xpath_tokens[3] == "enable") {
                                auto enable_str = request["value"].get<String>();
                                auto enable = Net::Interface::AdminState::ENABLED;
                                if (enable_str == "disable") {
                                    enable = Net::Interface::AdminState::DISABLED;
                                }

                                if (!std::dynamic_pointer_cast<InterfaceManager>(module_registry->interfaceModule())->setAdminState(iface_id, enable)) {
                                    spdlog::error("Failed to set state '{}' on the interface '{}'", enable, iface_id);
                                    return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                                }

                                return HTTP::StatusCode::OK;
                            }
                        }
                    }
                }
            }
        }
        else if (xpath_tokens[0] == "platform") {
            if (xpath_tokens[1] == "port") {
                if (xpath_tokens.size() == 2) {
                    if (op == "add") {
                        auto port_id = request["value"].get<String>();
                        if (!std::dynamic_pointer_cast<PortManager>(module_registry->portModule())->createPort(port_id)) {
                            spdlog::error("Failed to create port '{}'", port_id);
                            return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                        }

                        return HTTP::StatusCode::OK;
                    }
                }
                else if (xpath_tokens.size() == 4) {
                    if (xpath_tokens[3] == "breakout-mode") {
                        if (op == "add") {
                            auto port_id = xpath_tokens[2];
                            auto breakout_mode_str = request["value"].get<String>();
                            Net::Port::BreakoutMode breakout_mode = Net::Port::BreakoutMode::BREAKOUT_NONE;
                            if (breakout_mode_str == "4x100G") {
                                breakout_mode = Net::Port::BreakoutMode::BREAKOUT_4X100G;
                            }

                            if (!std::dynamic_pointer_cast<PortManager>(module_registry->portModule())->setPortBreakout(port_id, breakout_mode)) {
                                spdlog::error("Failed to set port breakout mode '{}' on the port '{}'", breakout_mode_str, port_id);
                                return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                            }

                            return HTTP::StatusCode::OK;
                        }
                    }
                }
            }            
        }
        else if (xpath_tokens[0] == "protocol") {
            if (xpath_tokens[1] == "lacp") {
                return HTTP::StatusCode::OK;
            }            
        }
        else if (xpath_tokens[0] == "vlan") {
            if (xpath_tokens.size() == 1) {
                if (op == "add") {
                    auto vlan_id = std::stoi(request["value"].get<String>().c_str());
                    if (!std::dynamic_pointer_cast<VlanManager>(module_registry->vlanModule())->createVlan(vlan_id)) {
                        spdlog::error("Failed to create VLAN '{}'", vlan_id);
                        return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                    }

                    return HTTP::StatusCode::OK;
                }
            }
            else if (xpath_tokens.size() == 4) {
                auto vlan_id = std::stoi(xpath_tokens[1]);
                if (xpath_tokens[2] == "members") {
                    if (xpath_tokens[3] == "tagged") {
                        auto iface_id = request["value"].get<String>();
                        if (op == "add") {
                            if (!std::dynamic_pointer_cast<VlanManager>(module_registry->vlanModule())->addTaggedMember(vlan_id, iface_id)) {
                                spdlog::error("Failed to add tagged member '{}' to VLAN '{}'", iface_id, vlan_id);
                                return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
                            }

                            return HTTP::StatusCode::OK;
                        }
                    }
                }
            }
        }

        spdlog::warn("Unsupported xpath '{}'", xpath);
        return HTTP::StatusCode::INTERNAL_SERVER_ERROR;
        // return config_mngr->makeCandidateConfig(data_request) ? HTTP::StatusCode::OK : HTTP::StatusCode::INTERNAL_SERVER_ERROR;
    });
    // TEST: END

    spdlog::info("Listening on connection from client...");
    if (!cm.run("127.0.0.1", 8000)) {
        spdlog::error("Failed to run connection management server");
        ::exit(EXIT_FAILURE);
    }

    #include <iostream>
    std::cin.get();
    ::exit(EXIT_SUCCESS);
}
