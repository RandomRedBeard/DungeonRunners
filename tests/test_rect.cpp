/**
 * @file test_rect.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <assert.h>


#include <rect.h>

using namespace std;
using namespace DR;

void test_cmp() {
    Rect r(0, 0, 12, 12);
    Rect r1(0, 0, 12, 12);

    assert(r == r1);
}

int main() {
    test_cmp();
    return 0;
}