/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include "node.hpp"
#include "visitor.hpp"
#include <lib/multiinherit_shared.hpp>
#include <lib/std_types.hpp>

namespace XPathNode {

class Composite
 : virtual public Node, public inheritable_enable_shared_from_this<Composite> {
  public:
    virtual ~Composite();
    Composite(const String name, SharedPtr<Node> parent = nullptr);

    virtual bool add(SharedPtr<Node> node);
    virtual bool remove(const String node_name);

    virtual SharedPtr<Node> makeCopy(SharedPtr<Node> parent = nullptr) const override;

    virtual void accept(Visitor& visitor) override;
    virtual SharedPtr<Node> findNode(const String node_name);
    virtual size_t count() const;

  private:
    Map<String, SharedPtr<Node>> _node_by_name;
};

} // namespace XPathNode
