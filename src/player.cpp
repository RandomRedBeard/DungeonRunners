/**
 * @file player.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "player.h"

DR::Player::Player(OID id) : id(id) {}

DR::Serial DR::Player::serialize(Serial& o) const noexcept {
    id.serialize(o);
    pt.serialize(o);
    o.put("name", name);
    return o;
}

void DR::Player::deserialize(const Serial& o) {
    id.deserialize(o);
    pt.deserialize(o);
    name = o.get<std::string>("name");
}