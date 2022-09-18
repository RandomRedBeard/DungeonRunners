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

DR::Player::Player() {}

DR::Player::Player(boost::uuids::uuid id) : id(id) {}

int DR::Player::takeDamage(int dmg) {
    return health -= dmg;
}

DR::Serial DR::Player::serialize(Serial& o) const noexcept {
    o.put("id", id);
    pt.serialize(o);
    o.put("name", name);
    return o;
}

void DR::Player::deserialize(const Serial& o) {
    id = o.get<boost::uuids::uuid>("id");
    pt.deserialize(o);
    name = o.get<std::string>("name");
}