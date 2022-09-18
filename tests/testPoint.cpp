/**
 * @file test_point.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include <point.h>

#include "testUtil.h"

void testConstructor() {
    Point pt;
    assert(pt.x == 0 && pt.y == 0);

    Point pt1(1, 1);
    assert(pt1.x == 1 && pt1.y == 1);

    Point pt2 = pt1;
    assert(pt2.x == 1 && pt2.y == 1);

    Point pt3 = move(pt1);
    assert(pt3.x == 1 && pt3.y == 1);
}

void testDist() {
    Point pt1, pt2(1, 1);

    assert(pt1.l1dist(pt2) == 2);

    pt2.x = 0;
    assert(pt1.dist(pt2) == 1);
}

void testUnitVector() {
    Point pt1(-2, -1), pt2(2, 2);

    assert(pt2.unitVector(pt1).x - (-4 / 5) < .00001);
}

void testEquals() {
    Point pt1(1, 1), pt2(1, 1);

    assert(pt1 == pt2);

    pt1.x = 2;

    assert(pt1 != pt2);
}

void testAssignment() {
    Point pt1(1, 1), pt2;

    pt2 = pt1;
    assert(pt2.x == 1 && pt2.y == 1);

    pt1.x = 10;
    pt2 = move(pt1);

    assert(pt2.x == 10 && pt2.y == 1);
}

void test_rand() {
    Point pt = Point::rand(10, 10);
}

int main() {
    testConstructor();
    testDist();
    testUnitVector();
    testEquals();
    testAssignment();
    test_rand();
    return 0;
}