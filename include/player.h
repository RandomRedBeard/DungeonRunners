/**
 * @file player.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>

#include <hasid.h>
#include <serializable.h>
#include <point.h>

namespace DR {
    class Player : public HasId, public Serializable {
        boost::uuids::uuid id;
        Point pt;
        int health;
        int maxHealth;
        std::string name;
    public:
        Player();
        Player(boost::uuids::uuid id);

        void setId(boost::uuids::uuid id) { this->id = id; }
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

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}