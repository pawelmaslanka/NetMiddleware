#pragma once

#include "module_registry.hpp"

#include "lib/lag_queryable.hpp"
#include "lib/observer.hpp"
#include "lib/std_types.hpp"

#include <grpcpp/grpcpp.h>
#include "lag.grpc.pb.h"

class LagManager final : public ILagQueryable, public Observer::IPublisher, public std::enable_shared_from_this<LagManager> {
public:
    LagManager(SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel);
    virtual ~LagManager() = default;

    bool createLag(const String& lag_id);
    bool deleteLag(const String& lag_id);

    bool addMember(const String& lag_id, const String& member_id);
    bool removeMember(const String& lag_id, const String& member_id);

    bool enableLacpProtocol(const String& lag_id, const bool enableLacpProto);

    virtual const SharedPtr<Lag> getLag(const String& lag_id) const override;

private:
    SharedPtr<ModuleRegistry> _module_registry;
    Map<String, SharedPtr<Lag>> _lag_by_id; // LAG by id
    Map<String, String> _lag_by_member;
    UniquePtr<Net::LagManagement::Stub> _lag_service;
};
