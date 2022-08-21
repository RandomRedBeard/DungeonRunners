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
#include <oid.h>
#include <serializable.h>
#include <point.h>

namespace DR {
    class Player : public HasId, public Serializable {
        OID id;
        Point pt;
        std::string name;
    public:
        Player(OID id);

        const OID getId() const noexcept { return id; }

        void setName(std::string name) noexcept { this->name = name; }
        std::string getName() const noexcept { return name; }

        void setPoint(Point pt) noexcept { this->pt = pt; }
        Point getPoint() const noexcept { return pt; };

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}