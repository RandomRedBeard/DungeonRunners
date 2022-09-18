/**
 * @file test_pathfinder.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <map.h>
#include <pathfinder.h>

#include "testUtil.h"

void testSamePoint() {
    Map m(80, 25, 3, 3);
    Pathfinder p = m.getPathfinder();

    Point r = m.randPoint();

    stack<int> path = p.findPath(r.index(m.getWidth()), r.index(m.getWidth()));
    assert(path.empty());
}

int main() {
    testSamePoint();
}