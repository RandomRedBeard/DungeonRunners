/**
 * @file hallway.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "hallway.h"

DR::Hallway::Hallway() {}

DR::Hallway::~Hallway() {}

bool DR::Hallway::operator==(const Hallway& h) const noexcept {
    return points == h.points;
}

bool DR::Hallway::operator!=(const Hallway& h) const noexcept {
    return !(Hallway::operator==(h));
}

DR::Serial DR::Hallway::serialize(Serial& o) const noexcept {
    Serial pts;
    for (auto &pt : points) {
        pts.push_back({"", pt.newSerialize()});
    }
    o.put_child("points", pts);
    return o;
}

void DR::Hallway::deserialize(const Serial& o) {
    for (auto &pt : o.get_child("points")) {
        Point p;
        p.deserialize(pt.second);
        points.push_back(p);
    }
}