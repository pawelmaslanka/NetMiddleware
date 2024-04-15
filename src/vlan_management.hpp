#pragma once

#include "lib/observer.hpp"
#include "lib/vlan_queryable.hpp"
#include "module_registry.hpp"

class VlanManager : public IVlanQueryable, public Observer::ISubscriber {
public:
    VlanManager(SharedPtr<ModuleRegistry> module_registry);
    virtual ~VlanManager() = default;

    bool createVlan(const UInt16 vid);
    bool deleteVlan(const UInt16 vid);

    bool addTaggedMember(const UInt16 vid, const String& member);
    bool removeTaggedMember(const UInt16 vid, const String& member);

    bool addUntaggedMember(const UInt16 vid, const String& member);
    bool removeUntaggedMember(const UInt16 vid, const String& member);

    bool setNativeVlan(const UInt16 vid, const String& member);
    bool removeNativeVlan(const UInt16 vid, const String& member);

    virtual const SharedPtr<Vlan> getVlan(const UInt16 vid) const override;
    virtual void handleEvent(SharedPtr<Observer::Event> event) override;

private:
    SharedPtr<ModuleRegistry> _module_registry;
    Map<UInt16, SharedPtr<Vlan>> _vlan_by_vid; // VLAN by vid
    // Ethernet port or LAG interface
    Map<String, UInt16> _tagged_vid_by_ifname;
    Map<String, UInt16> _untagged_vid_by_ifname;
    Map<String, UInt16> _native_vid_by_ifname;
};
