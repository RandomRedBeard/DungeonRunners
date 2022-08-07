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

#include <string>

#include <point.h>
#include <pathfinder.h>
#include <serializable.h>

namespace DR {
    class Monster : public Serializable {
        std::string name;
        Point pt;
    public:
        Monster(std::string name);

        void set_point(Point pt) noexcept { this->pt = pt; }
        Point get_point() const noexcept { return pt; };

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);
    };
}