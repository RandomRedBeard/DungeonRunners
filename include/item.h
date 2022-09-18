/**
 * @file item.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <point.h>
#include <serializable.h>

namespace DR {
    /**
     * @brief Parent class for all items
     *
     */
    class Item : public Serializable {
        Point pt;
        int lvl;
    public:
        Item(int lvl);

        int getLvl() const noexcept { return lvl; }

        void setPoint(Point pt) { this->pt = pt; }
        Point getPoint() const noexcept { return pt; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}