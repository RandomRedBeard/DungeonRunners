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

#include <assert.h>

#include <map.h>
#include <pathfinder.h>

void testSamePoint() {
    DR::Map m(80, 25, 3, 3);
    DR::Pathfinder p = m.getPathfinder();

    DR::Point r = m.randPoint();

    std::stack<int> path = p.findPath(r.index(m.getWidth()), r.index(m.getWidth()));
    assert(path.empty());
}

int main() {
    testSamePoint();
}