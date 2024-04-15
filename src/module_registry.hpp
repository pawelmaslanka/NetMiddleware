#pragma once

#include "lib/interface_queryable.hpp"
#include "lib/lag_queryable.hpp"
#include "lib/port_queryable.hpp"
#include "lib/vlan_queryable.hpp"

class ModuleRegistry {
public:
    ModuleRegistry()
    : _intf_module { std::dynamic_pointer_cast<IInterfaceQueryable>(MakeShared<NullInterfaceQueryable>()) },
        _lag_module { std::dynamic_pointer_cast<ILagQueryable>(MakeShared<NullLagQueryable>()) },
        _port_module { std::dynamic_pointer_cast<IPortQueryable>(MakeShared<NullPortQueryable>()) },
        _vlan_module { std::dynamic_pointer_cast<IVlanQueryable>(MakeShared<NullVlanQueryable>()) } {
            
        }

    inline const SharedPtr<IInterfaceQueryable> interfaceModule() const { return _intf_module; }
    inline void setInterfaceModule(SharedPtr<IInterfaceQueryable> intf_module) { _intf_module = intf_module; }
    inline const SharedPtr<ILagQueryable> lagModule() const { return _lag_module; }
    inline void setLagModule(SharedPtr<ILagQueryable> lag_module) { _lag_module = lag_module; }
    inline const SharedPtr<IPortQueryable> portModule() const { return _port_module; }
    inline void setPortModule(SharedPtr<IPortQueryable> port_module) { _port_module = port_module; }
    inline const SharedPtr<IVlanQueryable> vlanModule() const { return _vlan_module; }
    inline void setVlanModule(SharedPtr<IVlanQueryable> vlan_module) { _vlan_module = vlan_module; }
    // inline SharedPtr<Logging> logging() const { return nullptr; } // FIXME: Add implementation
    // inline WeakPtr<grpc::Channel> rpcNetChannel() { return _rpc_net_channel; }
    // inline void setRpcNetChannel(SharedPtr<grpc::Channel> rpc_net_channel) { _rpc_net_channel = rpc_net_channel; }

private:
    SharedPtr<IInterfaceQueryable> _intf_module;
    SharedPtr<ILagQueryable> _lag_module;
    SharedPtr<IPortQueryable> _port_module;
    SharedPtr<IVlanQueryable> _vlan_module;
    // SharedPtr<grpc::Channel> _rpc_net_channel;
};
