#pragma once

#include "lib/observer.hpp"
#include "module_registry.hpp"

#include <grpcpp/grpcpp.h>
#include <vlan.grpc.pb.h>
#include <net/vlan/vlan_queryable.hpp>
#include <lib/std_types.hpp>

namespace Net = Lib::Net;
namespace DPVlan = DataPlane::Vlan;

class VlanManager : public Net::IVlanQueryable, public Observer::ISubscriber {
public:
    VlanManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~VlanManager() = default;

    bool createVlan(const Net::Vlan::VID vid);
    bool deleteVlan(const Net::Vlan::VID vid);

    bool addTaggedMember(const Net::Vlan::VID vid, const Net::ID& member);
    bool removeTaggedMember(const Net::Vlan::VID vid, const Net::ID& member);

    bool addUntaggedMember(const Net::Vlan::VID vid, const Net::ID& member);
    bool removeUntaggedMember(const Net::Vlan::VID vid, const Net::ID& member);

    bool setNativeVlan(const Net::Vlan::VID vid, const Net::ID& member);
    bool removeNativeVlan(const Net::Vlan::VID vid, const Net::ID& member);

    virtual const WeakPtr<Net::Vlan> getVlan(const Net::Vlan::VID vid) const override;
    virtual void handleEvent(SharedPtr<Observer::Event> event) override;

private:
    String _module_name;
    SharedPtr<ModuleRegistry> _module_registry;
    UniquePtr<DPVlan::VlanManagement::Stub> _vlan_service;
    Map<UInt16, SharedPtr<Net::Vlan>> _vlan_by_vid; // VLAN by vid
    // Ethernet port or LAG interface
    Map<Net::ID, Net::Vlan::VID> _tagged_vid_by_ifname;
    Map<Net::ID, Net::Vlan::VID> _untagged_vid_by_ifname;
    Map<Net::ID, Net::Vlan::VID> _native_vid_by_ifname;
    SharedPtr<Log::Logger> _log;
};
