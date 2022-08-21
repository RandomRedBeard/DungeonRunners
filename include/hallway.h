/**
 * @file hallway.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <vector>

#include <serializable.h>
#include <point.h>

namespace DR {
    class Hallway : public Serializable {
        std::vector<Point> points;
    public:
        Hallway();
        virtual ~Hallway();

        void addPoint(Point pt) { points.push_back(pt); }
        const std::vector<Point> getPoints() const noexcept { return points; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);

        bool operator==(const Hallway& h) const noexcept;
        bool operator!=(const Hallway& h) const noexcept;
    };
}