/**
 * @file weapon.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "weapon.h"

DR::Weapon::Weapon(int min, int max, int lvl) : min(min), max(max), Item(lvl) {}