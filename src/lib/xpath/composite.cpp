/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#include "composite.hpp"

#include <iostream>

using namespace XPathNode;

Composite::Composite(const String name, SharedPtr<Node> parent)
 : Node(name, parent) {

}

Composite::~Composite() {
    for (auto& [_, node] : _node_by_name) {
        node.reset();
    }
}

bool Composite::add(SharedPtr<Node> node) {
    // if (!_node_by_name.insert({ node->name(), node }).second) {
    //     // std::cerr << "Node '" << node->name() << "' already exists in set of '" << name() << "'\n";
    //     return false;
    // }

    _node_by_name[node->name()] = node;
    node->setParent(Node::downcasted_shared_from_this<Composite>());
    return true;
}

bool Composite::remove(const String node_name) {
    auto node_it = _node_by_name.find(node_name);
    if (node_it == _node_by_name.end()) {
        return false;
    }

    node_it->second->setParent(nullptr);
    _node_by_name.erase(node_it);
    return true;
}

SharedPtr<Node> Composite::makeCopy(SharedPtr<Node> parent) const {
    auto copy_node = std::make_shared<Composite>(name());
    copy_node->setParent(parent ? parent : static_cast<const Node*>(this)->parent());
    for (auto& [name, node] : _node_by_name) {
        copy_node->_node_by_name.emplace(name, node->makeCopy(copy_node));
    }

    return copy_node;
}

// TODO: Get value from Visitor if it prefere DFS or BFS
void Composite::accept(Visitor& visitor) {
    for (auto node : _node_by_name) {
        if (!visitor.visit(node.second)) {
            break;
        }

        node.second->accept(visitor); // TODO: Czy to dobre? Nie przerwiemy rekurencji, bez mozliwosci zwrocenia true/false
    }
}

SharedPtr<Node> Composite::findNode(const String node_name) {
    auto node_it = _node_by_name.find(node_name);
    if (node_it != _node_by_name.end()) {
        return node_it->second;
    }

    return nullptr;
}

size_t Composite::count() const {
    return _node_by_name.size();
}
