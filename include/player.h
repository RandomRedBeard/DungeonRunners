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
    class Player : public Serializable, public HasId {
        OID id;
        Point pt;
        std::string name;
    public:
        Player(OID id);

        const OID get_id() const noexcept { return id; }

        void set_name(std::string name) noexcept { this->name = name; }
        std::string get_name() const noexcept { return name; }

        void set_point(Point pt) noexcept { this->pt = pt; }
        Point get_point() const noexcept { return pt; };

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);
    };
}