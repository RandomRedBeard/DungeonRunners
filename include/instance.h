/**
 * @file instance.h
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

#include <monster.h>
#include <player.h>
#include <map.h>
#include <oid.h>

namespace DR {
    /**
     * @brief A single map instance
     *
     */
    class Instance {
        // DMLayer will not own players
        std::map<OID, Player*> players;
        // This will own the monsters and map
        std::map<OID, Monster> monsters;
        Map pmap;

        // Map for cell lookup
    public:
        // Take ownership of map
        Instance(Map&& pmap);

        void generate_monsters(int n);
    };
}