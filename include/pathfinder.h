/**
 * @file pathfinder.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

 // unique_ptr include
#include <memory>
#include <map>
#include <vector>
#include <queue>
#include <stack>

#include <util.h>

namespace DR {
    class Pathfinder {
        using T = std::map<int, std::vector<int>>;
        T nodes;
    public:
        class Path {
            std::stack<int> path;
            int src, dest;
        public:
            Path(int src, int dest) : src(src), dest(dest) {}
            Path(std::stack<int> path, int src, int dest) : path(path), src(src), dest(dest) {}
            /**
              * @brief Deque next point
              *
              * @return int
              */
            int pop();
            bool empty() const noexcept { return path.empty(); }

            int get_src() const noexcept { return src; }
            int get_dest() const noexcept { return dest; }
        };

        Pathfinder();
        Pathfinder(const T& nodes);
        virtual ~Pathfinder();

        Path find_path(int src, int dest) const noexcept;
    };
}