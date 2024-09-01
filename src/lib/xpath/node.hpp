/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include "visitor.hpp"

#include <lib/multiinherit_shared.hpp>
#include <lib/std_types.hpp>

namespace XPathNode {

class Node : public IVisitable, public inheritable_enable_shared_from_this<Node> {
  public:
    virtual ~Node();
    Node(const String& name, SharedPtr<Node> parent = nullptr);
    String name() const;
    void setParent(SharedPtr<Node> parent);
    SharedPtr<Node> parent() const;
    virtual SharedPtr<Node> makeCopy(SharedPtr<Node> parent = nullptr) const;

    virtual void accept(Visitor& visitor) override;

  private:
    SharedPtr<Node> _parent;
    String _name;
};

} // namespace XPathNode
