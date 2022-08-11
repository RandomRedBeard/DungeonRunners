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

void test_same_points() {
    DR::Map m(DR::OID::generate(), 80, 25, 3, 3);
    DR::Pathfinder p = m.get_pathfinder();

    DR::Point r = m.get_rooms().begin()->second.rand_point();

    std::stack<int> path = p.find_path(r.index(m.get_width()), r.index(m.get_width()));
    assert(path.empty());
}

int main() {
    test_same_points();
}