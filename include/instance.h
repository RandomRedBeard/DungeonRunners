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

#include <hasid.h>
#include <monster.h>
#include <player.h>
#include <map.h>
#include <pathfinder.h>
#include <oid.h>

namespace DR {
    /**
     * @brief A single map instance
     *
     */
    class Instance {
    public:
        // DMLayer will not own players
        std::map<OID, Player*> players;
        // This will own the monsters and map
        std::map<OID, std::shared_ptr<Monster>> monsters;
        Map pmap;

        // Map for cell lookup
        std::map<int, std::weak_ptr<HasId>> cells;
        Point rand_point();
    public:
        // Take ownership of map
        Instance(Map&& pmap);

        bool is_walkable(int index);
        bool is_walkable(Point pt);

        void generate_monsters(int n);
    };
}