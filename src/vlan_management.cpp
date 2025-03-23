#include "vlan_management.hpp"

#include "lib/lag_observable.hpp"

#include <net/port/port_queryable.hpp>
#include <spdlog/spdlog.h>

VlanManager::VlanManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
  : _module_name { module_name }, _module_registry { module_registry },
    _vlan_service { DataPlane::Vlan::VlanManagement::NewStub(rpc_net_channel) }, ISubscriber { "VlanManager" },
    _log { module_registry->loggerRegistry()->getLogger(String(module_name)) } {

}

bool VlanManager::createVlan(const Net::Vlan::VID vid) {
    if (_vlan_by_vid.find(vid) != _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' already exists", vid);
        return false;
    }

    grpc::ClientContext context;
    DataPlane::Result result;
    DataPlane::Vlan::Vlan vlan;
    vlan.set_id(std::to_string(vid));
    auto status = _vlan_service->CreateVlan(&context, vlan, &result);
    if (!status.ok()) {
        _log->error("Failed to send request to create the vlan instance '{}': {} ({})",
            vid, status.error_message(), status.error_code());
        return false;
    }

    _vlan_by_vid[vid] = MakeSharedPtr<Net::Vlan>();
    return true;
}

bool VlanManager::deleteVlan(const Net::Vlan::VID vid) {
    // FIXME: Check all _*_by_ifname structures if they contain any reference to the 'vid'
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' not exists", vid);
        return false;
    }

    _vlan_by_vid.erase(vid);
    return true;
}

bool VlanManager::addTaggedMember(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                // FIXME: Push to stack original port VLAN
                // FIXME: Call RPC to directly set requested VLAN on the each of individual's LAG members
            }
        }
    }
    else {
        // FIXME: Call RPC to set tagged VLAN on the member interface
        grpc::ClientContext context;
        DataPlane::Result result;
        DPVlan::VlanMember vlan_members;
        vlan_members.set_vlan_id(std::to_string(vid));
        vlan_members.set_mode(DPVlan::VlanMode::VLAN_TAGGED);
        auto vlan_member = vlan_members.add_members();
        vlan_member->set_id(member);
        auto status = _vlan_service->AddVlanMember(&context, vlan_members, &result);
        if (!status.ok()) {
            _log->error("Failed to send request to add member to the VLAN instance '{}': {} ({})",
                vid, status.error_message(), status.error_code());
            return false;
        }
    }

    _vlan_by_vid[vid]->TaggedMembers.emplace(member);
    _tagged_vid_by_ifname[member] = vid;
    return true;
}

bool VlanManager::removeTaggedMember(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                auto tagged_member_it = _tagged_vid_by_ifname.find(lag_member);
                if (tagged_member_it != _tagged_vid_by_ifname.end()) {
                    // FIXME: Call RPC to restore original VLAN for the LAG member stored in 'tagged_member_it->second'
                }
            }
        }
    }
    else {
        // FIXME: Call RPC on the individual member
    }

    _vlan_by_vid[vid]->TaggedMembers.erase(member);
    _tagged_vid_by_ifname.erase(member);
    return true;
}

bool VlanManager::addUntaggedMember(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                // FIXME: Call RPC to directly set requested VLAN on the each of individual's LAG members
            }
        }
    }
    else {
        // FIXME: Call RPC to set tagged VLAN on the member interface
    }

    _vlan_by_vid[vid]->UntaggedMembers.emplace(member);
    _untagged_vid_by_ifname[member] = vid;
    return true;
}

bool VlanManager::removeUntaggedMember(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                auto untagged_member_it = _untagged_vid_by_ifname.find(lag_member);
                if (untagged_member_it != _untagged_vid_by_ifname.end()) {
                    // FIXME: Call RPC to restore original VLAN for the LAG member stored in 'untagged_member_it->second'
                }
            }
        }
    }
    else {
        // FIXME: Call RPC on the individual member
    }

    _vlan_by_vid[vid]->UntaggedMembers.erase(member);
    _untagged_vid_by_ifname.erase(member);
    return true;
}

bool VlanManager::setNativeVlan(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                // FIXME: Call RPC
            }
        }
    }
    else {
        // FIXME: Call RPC on the individual member
    }

    _vlan_by_vid[vid]->NativeMembers.emplace(member);
    _native_vid_by_ifname[member] = vid;
    return true;
}

bool VlanManager::removeNativeVlan(const Net::Vlan::VID vid, const Net::ID& member) {
    if (_vlan_by_vid.find(vid) == _vlan_by_vid.end()) {
        _log->error("VLAN ID '{}' does not exists", vid);
        return false;
    }

    if (member.find(Net::Lag::LAG_IFNAME_PREFIX) != StringEnd()) {
        auto lag_queryable = _module_registry->lagModule();
        auto lag_ptr = lag_queryable->getLag(member);
        if (auto lag = lag_ptr.lock()) {
            for (const auto& lag_member : lag->Members) {
                auto native_member_it = _native_vid_by_ifname.find(lag_member);
                auto native_vid = Net::Vlan::DEFAULT_VLAN;
                if (native_member_it != _native_vid_by_ifname.end()) {
                    native_vid = native_member_it->second;
                }

                // FIXME: Call RPC to restore original VLAN for the LAG member stored in 'native_vid'
            }
        }
    }
    else {
        // FIXME: Call RPC on the individual member
    }

    _vlan_by_vid[vid]->NativeMembers.erase(member);
    _native_vid_by_ifname.erase(member);
    return true;
}

const WeakPtr<Net::Vlan> VlanManager::getVlan(const Net::Vlan::VID vid) const {
    auto vlan_it = _vlan_by_vid.find(vid);
    if (vlan_it == _vlan_by_vid.end()) {
        return {};
    }

    return vlan_it->second;
}

void VlanManager::handleEvent(SharedPtr<Observer::Event> event) {
    if (!event) {
        _log->error("Passed null context from publisher");
        return;
    }

    if (auto lagAddMemberEvent = std::dynamic_pointer_cast<LagObservable::AddMemberEvent>(event)) {
        _log->info("[EVENT] Added member '{}' to LAG '{}'",
        lagAddMemberEvent->memberId(), lagAddMemberEvent->lagId());
        // TODO: Add new LAG member to VLAN
    }
    else if (auto lagRemoveMemberEvent = std::dynamic_pointer_cast<LagObservable::RemoveMemberEvent>(event)) {
        _log->info("[EVENT] Removed member '{}' to LAG '{}'",
        lagRemoveMemberEvent->memberId(), lagRemoveMemberEvent->lagId());
        // TODO: Remove LAG member from VLAN
    }
}
