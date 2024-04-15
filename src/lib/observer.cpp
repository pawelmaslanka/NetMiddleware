/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#include "lib/observer.hpp"

using namespace Observer;

// IPublisher::IPublisher(const Set<String>& allowed_events)
// : _allowed_events { allowed_events } {

// }

void IPublisher::notifySubscribers(SharedPtr<Event> ctx) {
    // if (_allowed_events.find(ctx.event) == _allowed_events.end()) {
    //     return;
    // }

    ForwardList<String> inactive_subscribers;
    for (auto& [id, subscriber] : _subscriber_by_id) {
        if (auto subscriber_ptr = subscriber.lock()) {
            subscriber_ptr->handleEvent(ctx);
        }
        else {
            inactive_subscribers.emplace_front(id);
        }
    }

    for (auto& id : inactive_subscribers) {
        _subscriber_by_id.erase(id);
    }
}

void IPublisher::subscribe(SharedPtr<ISubscriber> subscriber) {
    if (subscriber) {
        _subscriber_by_id[subscriber->id()] = subscriber;
    }
}

void IPublisher::unsubscribe(SharedPtr<ISubscriber> subscriber) {
    if (subscriber) {
        _subscriber_by_id.erase(subscriber->id());
    }
}

ISubscriber::ISubscriber(StringView id)
: _id { id } {

}

// void ISubscriber::setPublisher(SharedPtr<IPublisher> publisher) {
//     _publisher = publisher;
// }

String ISubscriber::id() {
    return _id;
}
