/**
 * @file test_hallway.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <hallway.h>

#include "testUtil.h"

void testJson() {
    Hallway h;
    h.addPoint({ 0, 0 });
    h.addPoint({ 1, 0 });

    Serial ptree;
    ptree = h.serialize(ptree);

    Hallway h1;
    h1.deserialize(ptree);

    assert(h1 == h);
}

int main() {
    testJson();
    return 0;
}