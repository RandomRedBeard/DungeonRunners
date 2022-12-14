/**
 * @file point.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "point.h"

DR::Point::Point(int x, int y) : x(x), y(y) {}

DR::Point::Point() : Point(0, 0) {}

DR::Point::~Point() {}

double DR::Point::dist(const Point pt) const noexcept {
    return std::sqrt(std::pow(x - pt.x, 2) + std::pow(y - pt.y, 2));
}

DR::DoublePoint DR::Point::unitVector(const Point pt) const noexcept {
    double mag = dist(pt);
    return DoublePoint((pt.x - x) / mag, (pt.y - y) / mag);
}

int DR::Point::l1dist(const Point pt) const noexcept {
    return std::abs(x - pt.x) + std::abs(y - pt.y);
}

int DR::Point::index(int width) const noexcept {
    return y * width + x;
}

DR::Point DR::Point::move(Direction d) const noexcept {
    switch (d)
    {
    case LEFT:
        return { x - 1, y };
    case RIGHT:
        return { x + 1, y };
    case UP:
        return { x, y - 1 };
    case DOWN:
        return { x, y + 1 };
    case NONE:
        return { x, y };
    }

    // Warning
    return {x, y};
}

DR::Serial DR::Point::serialize(Serial& o) const noexcept {
    o.put("x", x);
    o.put("y", y);
    return o;
}

void DR::Point::deserialize(const Serial& o) {
    x = o.get<int>("x", 0);
    y = o.get<int>("y", 0);
}

bool DR::Point::operator==(const Point& pt) const noexcept {
    return x == pt.x && y == pt.y;
}

bool DR::Point::operator!=(const Point& pt) const noexcept {
    return !(this->operator==(pt));
}

DR::Point DR::Point::rand(int x_upper, int y_upper) {
    return Point(std::rand() % x_upper, std::rand() % y_upper);
}

DR::Point DR::Point::index(int index, int width) {
    return { index % width, index / width };
}

DR::DoublePoint::DoublePoint(double x, double y) : x(x), y(y) {}

DR::DoublePoint::DoublePoint() : DoublePoint(0, 0) {}

double DR::DoublePoint::dist(const DoublePoint pt) const noexcept {
    return std::sqrt(std::pow(x - pt.x, 2) + std::pow(y - pt.y, 2));
}

double DR::DoublePoint::dist(const Point pt) const noexcept {
    return std::sqrt(std::pow(x - pt.x, 2) + std::pow(y - pt.y, 2));
}

DR::DoublePoint DR::DoublePoint::unitVector(const Point pt) const noexcept {
    double mag = dist(pt);
    return DoublePoint((pt.x - x) / mag, (pt.y - y) / mag);
}

DR::DoublePoint DR::DoublePoint::unitVector(const DoublePoint pt) const noexcept {
    double mag = dist(pt);
    return DoublePoint((pt.x - x) / mag, (pt.y - y) / mag);
}
