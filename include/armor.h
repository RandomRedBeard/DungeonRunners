/**
 * @file armor.h
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
    class Armor : public Item {
        int ac;
    public:
        Armor(int ac, int lvl);

        int getAc() const noexcept { return ac; }
    };
}