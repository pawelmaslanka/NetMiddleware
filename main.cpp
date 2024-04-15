#include "interface_management.hpp"
#include "lag_management.hpp"
#include "port_management.hpp"
#include "vlan_management.hpp"

#include "module_registry.hpp"

#include <spdlog/spdlog.h>

#include <cstdlib>

#include <grpcpp/grpcpp.h>

int main(const int argc, const char* argv[]) {
    auto module_registry = MakeShared<ModuleRegistry>();
    auto rpc_net_channel = grpc::CreateChannel("localhost:50052", grpc::InsecureChannelCredentials());
    auto intf_mngr = MakeShared<InterfaceManager>(module_registry);
    auto lag_mngr = MakeShared<LagManager>(module_registry, rpc_net_channel);
    auto port_mngr = MakeShared<PortManager>(module_registry);
    auto vlan_mngr = MakeShared<VlanManager>(module_registry);
    module_registry->setInterfaceModule(intf_mngr);
    module_registry->setLagModule(lag_mngr);
    module_registry->setPortModule(port_mngr);
    module_registry->setVlanModule(vlan_mngr);

    // TEST: BEG
    auto lag1_id = "lag-1";
    if (!lag_mngr->createLag(lag1_id)) {
        spdlog::error("Failed to create LAG '{}'", lag1_id);
        ::exit(EXIT_FAILURE);
    }

    auto eth1_1_id = "eth-1/1";
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

    auto eth1_2_id = "eth-1/2";
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
