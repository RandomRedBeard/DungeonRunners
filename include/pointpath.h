/**
 * @file point_path.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <pathfinder.h>
#include <point.h>

namespace DR {
    class PointPath {
        std::stack<int> path;
        Point src, dest;
        int width;
    public:
        PointPath();
        PointPath(std::stack<int> path, Point src, Point dest, int width);

        Point top();
        void pop();
        bool empty() const noexcept { return path.empty(); }

        Point get_src() const noexcept { return src; }
        Point get_dest() const noexcept { return dest; }
    };
}