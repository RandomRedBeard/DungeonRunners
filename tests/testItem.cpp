/**
 * @file testItem.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <item.h>
#include <weapon.h>
#include <armor.h>

#include "testUtil.h"

void testItem() {
    Item item(1);
    item.print();
}

void testCast() {
    auto w = make_shared<Weapon>(5, 10, 1);
    auto i = dynamic_pointer_cast<Item>(w);
    assert(i != nullptr);
    auto a = dynamic_pointer_cast<Armor>(i);
    assert(a == nullptr);
    w = dynamic_pointer_cast<Weapon>(i);
    assert(w != nullptr);
}

int main() {
    testItem();
    testCast();
}