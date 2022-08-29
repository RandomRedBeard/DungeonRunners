/**
 * @file monster.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "monster.h"

DR::Monster::Monster() {}

DR::Monster::Monster(OID id, std::string name) : id(id), name(name) {}

DR::Serial DR::Monster::serialize(Serial& o) const noexcept {
    id.serialize(o);
    o.put("name", name);
    pt.serialize(o);
    o.put("speed", speed);
    return o;
}

void DR::Monster::deserialize(const Serial& o) {
    id.deserialize(o);
    name = o.get<std::string>("name");
    pt.deserialize(o);
    o.get<int>("speed", speed);
}