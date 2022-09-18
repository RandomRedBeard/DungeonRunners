/**
 * @file item.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "item.h"

DR::Item::Item(int lvl) : lvl(lvl) {}

DR::Serial DR::Item::serialize(Serial& o) const noexcept {
    pt.serialize(o);
    o.put("level", lvl);
    return o;
}

void DR::Item::deserialize(const Serial& o) {
    pt.deserialize(o);
    lvl = o.get<int>("level");
}