#include "lag_management.hpp"

#include "lib/lag_observable.hpp"
#include <spdlog/spdlog.h>

LagManager::LagManager(SharedPtr<ModuleRegistry> module_registry, SharedPtr<grpc::Channel> rpc_net_channel)
: _module_registry { module_registry }, _lag_service { Net::Lag::NewStub(rpc_net_channel) } {
}

bool LagManager::createLag(const String& lag_id) {
    if (_lag_by_id.find(lag_id) != _lag_by_id.end()) {
        spdlog::error("LAG '{}' already exists", lag_id);
        return false;
    }

    // FIXME: Call RPC
    _lag_by_id[lag_id] = MakeShared<Lag>();
    return true;
}

bool LagManager::deleteLag(const String& lag_id) {
    if (_lag_by_id.find(lag_id) == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    // FIXME: Call RPC
    _lag_by_id.erase(lag_id);
    return true;
}

bool LagManager::addMember(const String& lag_id, const String& member) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    // FIXME: Call RPC
    lag_it->second->Members.emplace(member);
    notifySubscribers(MakeShared<LagObservable::AddMemberEvent>(shared_from_this(), lag_id, member));
    return true;
}

bool LagManager::removeMember(const String& lag_id, const String& member) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    // FIXME: Call RPC
    lag_it->second->Members.erase(member);
    notifySubscribers(MakeShared<LagObservable::RemoveMemberEvent>(shared_from_this(), lag_id, member));
    return true;
}

bool LagManager::enableLacpProtocol(const String& lag_id, const bool enableLacp) {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        spdlog::error("LAG '{}' not exists", lag_id);
        return false;
    }

    auto oldLagType = lag_it->second->Type;
    lag_it->second->Type = enableLacp ? Lag::LagType::DYNAMIC : Lag::LagType::STATIC;
    if (oldLagType != lag_it->second->Type) {
        if (lag_it->second->Type == Lag::LagType::DYNAMIC) {
            // FIXME: Remove all members from static LAG and re-add them dynamically by LACP
        }
        // FIXME: Call RPC
    }

    return true;
}

const SharedPtr<Lag> LagManager::getLag(const String& lag_id) const {
    auto lag_it = _lag_by_id.find(lag_id);
    if (lag_it == _lag_by_id.end()) {
        return nullptr;
    }

    return lag_it->second;
}
