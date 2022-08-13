/**
 * @file dm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <map>
#include <vector>

#include <player.h>
#include <monster.h>
#include <map.h>

namespace DR {
    /**
     * @brief Handles all global game operations
     * (e.g) New players, leaving players, any locking/threading
     * 
     */
    class DM {
        // Owning players
        std::vector<std::shared_ptr<Player>> players;
    };
}