#include "interface_management.hpp"
#include "lag_management.hpp"
#include "port_management.hpp"
#include "vlan_management.hpp"

#include "module_names.hpp"
#include "module_registry.hpp"

// #include "lib/log_management.hpp"
#include "lib/log.hpp"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <cstdlib>

#include <grpcpp/grpcpp.h>

int main(const int argc, const char* argv[]) {
    auto console_sink = MakeShared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::trace);
    console_sink->set_pattern("%+");

    auto file_sink = MakeShared<spdlog::sinks::basic_file_sink_mt>("/tmp/netmiddleware.log", true);
    file_sink->set_level(spdlog::level::trace);
    file_sink->set_pattern("%+");

    auto loggers_registry = MakeShared<Log::LoggersRegistry>(spdlog::sinks_init_list{ console_sink, file_sink });
    loggers_registry->registerModule(Module::Name::IFACE_MANAGER);
    loggers_registry->getLogger(Module::Name::IFACE_MANAGER)->set_level(spdlog::level::info);

    auto module_registry = MakeShared<ModuleRegistry>();
    module_registry->setLogModule(loggers_registry);
    auto rpc_net_channel = grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials());
    auto intf_mngr = MakeShared<InterfaceManager>(Module::Name::IFACE_MANAGER, module_registry, rpc_net_channel);
    auto lag_mngr = MakeShared<LagManager>(module_registry, rpc_net_channel);
    auto port_mngr = MakeShared<PortManager>(module_registry, rpc_net_channel);
    auto vlan_mngr = MakeShared<VlanManager>(module_registry);
    module_registry->setInterfaceModule(intf_mngr);
    module_registry->setLagModule(lag_mngr);
    module_registry->setPortModule(port_mngr);
    module_registry->setVlanModule(vlan_mngr);

    // TEST: BEG
    String eth1_10_id = "eth1-10";
    if (!port_mngr->createPort(eth1_10_id)) {
        spdlog::error("Failed to create port '{}'", eth1_10_id);
        ::exit(EXIT_FAILURE);
    }

    if (!port_mngr->setPortBreakout(eth1_10_id, Port::BreakoutMode::BREAKOUT_4X100G)) {
        spdlog::error("Failed to set port breakout mode '{}' on the port '{}'", Port::BreakoutMode::BREAKOUT_4X100G, eth1_10_id);
        ::exit(EXIT_FAILURE);
    }

    String eth1_10_1_id = eth1_10_id + "_1";
    if (!intf_mngr->createInterface(eth1_10_1_id)) {
        spdlog::error("Failed to create the interface '{}'", eth1_10_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!intf_mngr->setSpeed(eth1_10_1_id, Interface::LinkSpeed::SPEED_100G)) {
        spdlog::error("Failed to set speed '{}' on the interface '{}'", Interface::LinkSpeed::SPEED_100G, eth1_10_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!intf_mngr->setAdminState(eth1_10_1_id, Interface::AdminState::ENABLED)) {
        spdlog::error("Failed to set state '{}' on the interface '{}'", Interface::AdminState::ENABLED, eth1_10_1_id);
        ::exit(EXIT_FAILURE);
    }

    auto eth1_1_id = "eth1-1";
    if (!port_mngr->createPort(eth1_1_id)) {
        spdlog::error("Failed to create port '{}'", eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!port_mngr->setPortBreakout(eth1_1_id, Port::BreakoutMode::BREAKOUT_NONE)) {
        spdlog::error("Failed to set port breakout mode '{}' on the port '{}'", Port::BreakoutMode::BREAKOUT_NONE, eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!intf_mngr->createInterface(eth1_1_id)) {
        spdlog::error("Failed to create the interface '{}'", eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!intf_mngr->setSpeed(eth1_1_id, Interface::LinkSpeed::SPEED_400G)) {
        spdlog::error("Failed to set speed '{}' on the interface '{}'", Interface::LinkSpeed::SPEED_400G, eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!intf_mngr->setAdminState(eth1_1_id, Interface::AdminState::ENABLED)) {
        spdlog::error("Failed to set state '{}' on the interface '{}'", Interface::AdminState::ENABLED, eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    auto lag1_id = "lag-1";
    if (!lag_mngr->createLag(lag1_id)) {
        spdlog::error("Failed to create LAG '{}'", lag1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!lag_mngr->addMember(lag1_id, eth1_1_id)) {
        spdlog::error("Failed to add member '{}' to LAG '{}'", eth1_1_id, lag1_id);
        ::exit(EXIT_FAILURE);
    }

    auto vid2 = 2;
    if (!vlan_mngr->createVlan(vid2)) {
        spdlog::error("Failed to create VLAN '{}'", vid2);
        ::exit(EXIT_FAILURE);
    }

    if (!vlan_mngr->addTaggedMember(vid2, lag1_id)) {
        spdlog::error("Failed to add tagged member '{}' to VLAN '{}'", lag1_id, vid2);
        ::exit(EXIT_FAILURE);
    }

    spdlog::info("Subscribe VLAN manager to LAG manager");
    lag_mngr->subscribe(vlan_mngr);

    auto eth1_2_id = "eth1-2";
    if (!lag_mngr->addMember(lag1_id, eth1_2_id)) {
        spdlog::error("Failed to add member '{}' to LAG '{}'", eth1_2_id, lag1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!vlan_mngr->removeTaggedMember(vid2, lag1_id)) {
        spdlog::error("Failed to remove tagged member '{}' to VLAN '{}'", lag1_id, vid2);
        ::exit(EXIT_FAILURE);
    }

    if (!vlan_mngr->deleteVlan(vid2)) {
        spdlog::error("Failed to delete VLAN '{}'", vid2);
        ::exit(EXIT_FAILURE);
    }

    if (!lag_mngr->removeMember(lag1_id, eth1_1_id)) {
        spdlog::error("Failed to remove member '{}' from LAG '{}'", eth1_1_id);
        ::exit(EXIT_FAILURE);
    }

    if (!lag_mngr->deleteLag(lag1_id)) {
        spdlog::error("Failed to delete LAG '{}'", lag1_id);
        ::exit(EXIT_FAILURE);
    }

    spdlog::info("Successfully passed test");
    // TEST: END

    ::exit(EXIT_SUCCESS);
}
