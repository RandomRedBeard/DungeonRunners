/**
 * @file test_room.cpp
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

#include <room.h>


using namespace std;
using namespace DR;

void test_json() {
    Room r = Rect({0, 0, 10, 10});

    json_t* o = r.new_json();
    char* buf = json_dumps(o, JSON_INDENT(4));

    puts(buf);
}

int main() {
    test_json();
}