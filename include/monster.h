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
    class Monster : public HasId, public Serializable {
        boost::uuids::uuid id;
        std::string name;
        Point pt;
        int health;
        int maxHealth;
        PointPath path;
        int speed = NORMAL;
        std::chrono::steady_clock::time_point last_moved;
    public:
        Monster();
        Monster(boost::uuids::uuid id, std::string name);

        const boost::uuids::uuid getId() const noexcept { return id; }

        void setName(std::string name) noexcept { this->name = name; }
        std::string getName() const noexcept { return name; }

        void setPoint(Point pt) noexcept { this->pt = pt; }
        Point getPoint() const noexcept { return pt; };

        void setHealth(int health) { this->health = maxHealth = health; }
        int takeDamage(int dmg);
        int getHealth() const noexcept { return health; }
        int getMaxHealth() const noexcept { return maxHealth; }
        bool isAlive() const noexcept { return health > 0; }

        void setPath(PointPath path) { this->path = path; }
        PointPath getPath() { return path; }

        int getSpeed() const noexcept { return speed; }
        void setSpeed(int speed) { this->speed = speed; }

        const std::chrono::steady_clock::time_point getLastMoved() const noexcept { return last_moved; }
        void setLastMoved(std::chrono::steady_clock::time_point tm) { last_moved = tm; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}