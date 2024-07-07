#pragma once

#include <net/interface/interface_queryable.hpp>
#include <net/lag/lag_queryable.hpp>
#include <net/port/port_queryable.hpp>
#include <net/vlan/vlan_queryable.hpp>

#include <std_types.hpp>

namespace Lib::Net {

class ModuleRegistry {
public:
    ModuleRegistry()
      : _intf_module { std::dynamic_pointer_cast<Net::IInterfaceQueryable>(MakeShared<Net::NullInterfaceQueryable>()) },
        _lag_module { std::dynamic_pointer_cast<Net::ILagQueryable>(MakeShared<Net::NullLagQueryable>()) },
        _port_module { std::dynamic_pointer_cast<Net::IPortQueryable>(MakeShared<Net::NullPortQueryable>()) },
        _vlan_module { std::dynamic_pointer_cast<Net::IVlanQueryable>(MakeShared<Net::NullVlanQueryable>()) } {
            // Nothing more to do
        }

    inline const SharedPtr<Net::IInterfaceQueryable> interfaceModule() const { return _intf_module; }
    inline void setInterfaceModule(SharedPtr<Net::IInterfaceQueryable> intf_module) { _intf_module = intf_module; }
    inline const SharedPtr<Net::ILagQueryable> lagModule() const { return _lag_module; }
    inline void setLagModule(SharedPtr<Net::ILagQueryable> lag_module) { _lag_module = lag_module; }
    inline const SharedPtr<Net::IPortQueryable> portModule() const { return _port_module; }
    inline void setPortModule(SharedPtr<Net::IPortQueryable> port_module) { _port_module = port_module; }
    inline const SharedPtr<Net::IVlanQueryable> vlanModule() const { return _vlan_module; }
    inline void setVlanModule(SharedPtr<Net::IVlanQueryable> vlan_module) { _vlan_module = vlan_module; }
    // inline SharedPtr<Logging> logging() const { return nullptr; } // FIXME: Add implementation
    // inline WeakPtr<grpc::Channel> rpcNetChannel() { return _rpc_net_channel; }
    // inline void setRpcNetChannel(SharedPtr<grpc::Channel> rpc_net_channel) { _rpc_net_channel = rpc_net_channel; }

private:
    SharedPtr<Net::IInterfaceQueryable> _intf_module;
    SharedPtr<Net::ILagQueryable> _lag_module;
    SharedPtr<Log::LoggersRegistry> _log_module;
    SharedPtr<Net::IPortQueryable> _port_module;
    SharedPtr<Net::IVlanQueryable> _vlan_module;
    // SharedPtr<grpc::Channel> _rpc_net_channel;
};

} // namespace Lib::Net
