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