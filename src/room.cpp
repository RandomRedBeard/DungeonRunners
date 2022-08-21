/**
 * @file room.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "room.h"

DR::Room::Room() : Rect() {
    lit = false;
}

DR::Room::Room(const Rect& r) : Rect(r) {
    lit = false;
}

DR::Serial DR::Room::serialize(Serial& o) const noexcept {
    o = Rect::serialize(o);
    o.put("lit", lit);
    o.put_child("no", no.newSerialize());
    o.put_child("so", so.newSerialize());
    o.put_child("ea", ea.newSerialize());
    o.put_child("we", we.newSerialize());
    return o;
}

void DR::Room::deserialize(const Serial& o) {
    Rect::deserialize(o);
    lit = o.get<bool>("lit");
    no.deserialize(o.get_child("no"));
    so.deserialize(o.get_child("so"));
    ea.deserialize(o.get_child("ea"));
    we.deserialize(o.get_child("we"));
}

DR::Point DR::Room::randPoint() const noexcept {
    return { x + 1 + rand() % (w - 2), y + 1 + rand() % (h - 2) };
}

bool DR::Room::operator==(const Room& r) const noexcept {
    return Rect::operator==(r) && lit == r.lit && no == r.no && so == r.so && ea == r.ea && we == r.we;
}

bool DR::Room::operator!=(const Room& r) const noexcept {
    return !(this->operator==(r));
}
