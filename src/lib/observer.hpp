/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include "lib/std_types.hpp"

// This is a typical interface of Observer Design Pattern. In this namespace there is interface
// called IPublisher which should be implemented by the object which want to notify its subscribers
// about some changes made in it. The interface ISubscriber is implemented by object which want to
// receive notifications about the events made in observed object.
namespace Observer {

// using EventT = String;

struct Event {
    virtual ~Event() = default;
};

class ISubscriber;
class IPublisher {
public:
    // IPublisher(const Set<EventT>& allowed_events);
    virtual ~IPublisher() = default;
    void notifySubscribers(SharedPtr<Event> event);
    void subscribe(SharedPtr<ISubscriber> subscriber);
    void unsubscribe(SharedPtr<ISubscriber> subscriber);

protected:
    Map<String, WeakPtr<ISubscriber>> _subscriber_by_id;
    // Set<EventT> _allowed_events;
};

class ISubscriber {
protected:
    friend IPublisher;
    ISubscriber() = delete;
    ISubscriber(StringView id);
    virtual ~ISubscriber() = default;
    // void setPublisher(SharedPtr<IPublisher> publisher);
    virtual void handleEvent(SharedPtr<Event> event) = 0;
    String id();

private:
    SharedPtr<IPublisher> _publisher;
    String _id;
};

} // namspace Observer
