/**
 * @file test_message.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <message.h>
#include <point.h>

#include "testUtil.h"

void testMessage() {
    Serial o = Point().newSerialize();
    Message m("point", std::move(o));

    m.print();
}

void testBoost() {
    boost::property_tree::ptree array, elem, root;
    elem.put("", 1);
    array.push_back({ "", elem });
    array.push_back({ "", elem });

    root.put_child("array", array);

    boost::property_tree::write_json(std::cout, root);

    for (auto &p : root.get_child("array")) {
        std::cout << "elem" << p.second.get<int>("");
    }
}

int main() {
    testMessage();
    testBoost();
    return 0;
}