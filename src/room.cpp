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

DR::Point DR::Room::rand_point() const noexcept {
    return { x + 1 + rand() % (w - 2), y + 1 + rand() % (h - 2) };
}

bool DR::Room::operator==(const Room& r) const noexcept {
    return Rect::operator==(r) && lit == r.lit && no == r.no && so == r.so && ea == r.ea && we == r.we;
}

bool DR::Room::operator!=(const Room& r) const noexcept {
    return !(this->operator==(r));
}
