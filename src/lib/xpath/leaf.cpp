// /*
//  * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
//  * This program is free software: you can redistribute it and/or modify it under the terms
//  * of the GNU General Public License as published by the Free Software Foundation, version 3.
//  */
// #include "leaf.hpp"

// #include <iostream>

// using namespace XPathNode;

// Leaf::Leaf(const String& name, const Value value, SharedPtr<Node> parent, SharedPtr<Node> schema_node)
// : Node(name, parent, schema_node), m_value(value) {

// }

// void Leaf::setValue(const Value value) {
//     m_value = value;
// }

// Value Leaf::getValue() const {
//     return m_value;
// }

// SharedPtr<Node> Leaf::makeCopy(SharedPtr<Node> parent) const {
//     auto copy_node = std::make_shared<Leaf>(name(), m_value);
//     copy_node->setParent(parent ? parent : parent());
//     copy_node->SetSchemaNode(SchemaNode());

//     return copy_node;
// }

// void Leaf::accept(Visitor& visitor) {

// }
