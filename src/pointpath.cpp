/**
 * @file point_path.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "pointpath.h"

DR::PointPath::PointPath() {
    width = -1;
}

DR::PointPath::PointPath(std::stack<int> path, Point src, Point dest, int width) : path(path), src(src), dest(dest), width(width) {}

DR::Point DR::PointPath::top() {
    if (width == -1) {
        return Point();
    }
    if (path.empty()) {
        return Point();
    }

    int i = path.top();
    return Point::index(i, width);
}


void DR::PointPath::pop() {
    path.pop();
}
