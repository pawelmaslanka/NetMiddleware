#pragma once

#include "module_registry.hpp"

#include "lib/observer.hpp"

#include <grpcpp/grpcpp.h>
#include <lag.grpc.pb.h>
#include <net/lag/lag_queryable.hpp>
#include <lib/std_types.hpp>

namespace Net = Lib::Net;
namespace DPLag = DataPlane::Lag;

class LagManager final : public Net::ILagQueryable, public Observer::IPublisher, public std::enable_shared_from_this<LagManager> {
public:
    LagManager(StringView module_name, SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~LagManager() = default;

    bool createLag(const Net::ID& lag_id, const String& mac_address);
    bool deleteLag(const Net::ID& lag_id);

    bool addMember(const Net::ID& lag_id, const Net::ID& member_id);
    bool removeMember(const Net::ID& lag_id, const Net::ID& member_id);

    bool enableLacpProtocol(const Net::ID& lag_id, const bool enableLacpProto);

    virtual const WeakPtr<Net::Lag> getLag(const Net::ID& lag_id) const override;

private:
    String _module_name;
    SharedPtr<ModuleRegistry> _module_registry;
    Map<Net::ID, SharedPtr<Net::Lag>> _lag_by_id; // LAG by id
    Map<Net::ID, String> _lag_by_member;
    UniquePtr<DPLag::LagManagement::Stub> _lag_service;
    SharedPtr<Log::Logger> _log;
};
