/**
 * @file weapon.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <item.h>

namespace DR {
    class Weapon : public Item {
        int min, max;
    public:
        Weapon(int min, int max, int lvl);

        int getMin() const noexcept { return min; }
        int getMax() const noexcept { return max; }
    };
}