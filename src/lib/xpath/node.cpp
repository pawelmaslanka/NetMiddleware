/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#include "node.hpp"
#include "leaf.hpp"

#include <iostream>

using namespace XPathNode;

Node::Node(const String& name, SharedPtr<Node> parent)
 : _name { name }, _parent { parent } {

}

Node::~Node() {
    _parent.reset();
}

String Node::name() const {
    return _name;
}

void Node::setParent(SharedPtr<Node> parent) {
    _parent = parent;
}

SharedPtr<Node> Node::parent() const {
    return _parent;
}

SharedPtr<Node> Node::makeCopy(SharedPtr<Node> parent) const {
    auto copy_node = std::make_shared<Node>(_name);
    copy_node->_parent = parent ? parent : _parent;
    return copy_node;
}

void Node::accept(Visitor& visitor) {
    visitor.visit(shared_from_this());
}
