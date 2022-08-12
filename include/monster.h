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
#include <pointpath.h>
#include <serializable.h>
#include <util.h>
#include <hasid.h>

namespace DR {
    class Monster : public Serializable, public HasId {
        OID id;
        std::string name;
        Point pt;
        PointPath path;
        int speed = NORMAL;
        std::chrono::steady_clock::time_point last_moved;
    public:
        Monster(OID id, std::string name);

        const OID get_id() const noexcept { return id; }

        void set_point(Point pt) noexcept { this->pt = pt; }
        Point get_point() const noexcept { return pt; };

        void set_path(PointPath path) { this->path = path; }
        PointPath get_path() { return path; }

        int get_speed() const noexcept { return speed; }
        void set_speed(int speed) { this->speed = speed; }

        const std::chrono::steady_clock::time_point get_last_moved() const noexcept { return last_moved; }
        void set_last_moved(std::chrono::steady_clock::time_point tm) { last_moved = tm; }

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);
    };
}