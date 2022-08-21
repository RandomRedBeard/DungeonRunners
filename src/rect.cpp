/**
 * @file rect.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "rect.h"

DR::Rect::Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

DR::Rect::Rect() : Rect(0, 0, 0, 0) {}

bool DR::Rect::contains(const Point pt) const noexcept {
    return pt.x >= x && pt.x < x + w && pt.y >= y && pt.y < y + h;
}

unsigned int DR::Rect::area() const noexcept {
    return h * w;
}

DR::Serial DR::Rect::serialize(Serial& o) const noexcept {
    o.put("x", x);
    o.put("y", y);
    o.put("w", w);
    o.put("h", h);
    return o;
}

void DR::Rect::deserialize(const Serial& o) {
    x = o.get<int>("x", 0);
    y = o.get<int>("y", 0);
    w = o.get<int>("w", 0);
    h = o.get<int>("h", 0);
}

bool DR::Rect::operator==(const Rect& r) const noexcept {
    return x == r.x && y == r.y && w == r.w && h == r.h;
}

bool DR::Rect::operator!=(const Rect& r) const noexcept {
    return !(this->operator==(r));
}
