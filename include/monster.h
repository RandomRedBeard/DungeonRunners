/**
 * @file monster.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <chrono>
#include <string>

#include <point.h>
#include <pathfinder.h>
#include <serializable.h>
#include <constants.h>

namespace DR {
    class Monster : public Serializable {
        std::string name;
        Point pt;
        Speed speed = NORMAL;
        std::chrono::steady_clock::time_point last_moved;
    public:
        Monster(std::string name);

        void set_point(Point pt) noexcept { this->pt = pt; }
        Point get_point() const noexcept { return pt; };

        const Speed get_speed() const noexcept { return speed; }
        void set_speed(Speed speed) { this->speed = speed; }

        const std::chrono::steady_clock::time_point get_last_moved() const noexcept { return last_moved; }
        void set_last_moved(std::chrono::steady_clock::time_point tm) { last_moved = tm; }

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);
    };
}