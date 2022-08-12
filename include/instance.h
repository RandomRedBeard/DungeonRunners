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
#include <oid.h>

namespace DR {
    /**
     * @brief A single map instance
     *
     */
    class Instance {
    public:
        // DMLayer will not own players
        std::map<OID, std::weak_ptr<Player>> players;
        // This will own the monsters and map
        std::map<OID, std::shared_ptr<Monster>> monsters;
        Map pmap;

        // Map for unique cell placement
        // Weak pointer for non-owning
        std::map<int, std::weak_ptr<HasId>> unique_cells;

        std::map<int, std::weak_ptr<HasId>> shared_cells;

        /**
         * @brief pmap.rand_point + unique_cell consideration
         *
         * @return Point
         */
        Point rand_point() const noexcept;
    public:
        // Take ownership of map
        Instance(Map&& pmap);
        virtual ~Instance();

        void add_player(std::weak_ptr<Player> p, Point pt);

        void generate_monsters(int n);

        /**
         * @brief Updates unique_cell map if move can be completed
         * without conflict (i.e is_walkable check)
         *
         * @param o
         * @param src
         * @param dest
         * @return true
         * @return false
         */
        bool move(std::weak_ptr<HasId> o, Point src, Point dest);

        bool is_walkable(int index) const noexcept;
        bool is_walkable(Point pt) const noexcept;
    };
}