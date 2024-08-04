/*
 * Copyright (C) 2024 Pawel Maslanka (pawmas@hotmail.com)
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, version 3.
 */
#pragma once

#include <lib/std_types.hpp>

#include <iostream>

#include <list>
#include <optional>

namespace Graph {
    class Node {
     public:
        Node() = delete;
        explicit Node(std::string_view name);
        ~Node() = default;

        void addEdge(SharedPtr<Node> node);
        const std::string& name() const;
        std::list<SharedPtr<Node>>& edges();

        bool operator==(const Node& another) const;

     private:
        std::string _name;
        std::list<SharedPtr<Node>> _edges;
    };

    std::optional<std::string> depResolve(SharedPtr<Graph::Node> node,
        std::list<SharedPtr<Graph::Node>>& resolved, std::list<SharedPtr<Graph::Node>>& unresolved);
} // namespace Graph

std::optional<std::string> makeGraphNode(std::map<std::string, std::set<std::string>>& adj_list, Graph::Node& node);
std::optional<std::string> run_update_op(SharedPtr<Map<String, Set<String>>> cmds, std::list<String>& ordered_cmds);

// int main(int argc, char* argv[]) {
//         auto depends = make_map<String, Set<String>>();
//         (*depends)["/interface/ethernet[@item]"].emplace("/platform/port[@item]/num_breakout");
//         (*depends)["/interface/aggregate[@item]/members"].emplace("/interface/ethernet[@item]");
//         (*depends)["/interface/ethernet[@item]/speed"].emplace("/platform/port[@item]/breakout_speed");
//         (*depends)["/platform/port[@item]/breakout_speed"].emplace("/platform/port[@item]/num_breakout");
//         run_update_op(depends);
//         return 0;
// }