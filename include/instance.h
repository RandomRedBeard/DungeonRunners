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
#include <string>
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
    class Instance : public Serializable {
    public:
        // DMLayer will not own players
        std::map<OID, std::weak_ptr<Player>> players;
        // This will own the monsters and map
        std::map<OID, std::shared_ptr<Monster>> monsters;
        Map pmap;

        // Map for unique cell placement
        // Weak pointer for non-owning
        std::map<int, std::weak_ptr<HasId>> uniqueCells;

        /**
         * @brief pmap.rand_point + unique_cell consideration
         *
         * @return Point
         */
        Point randPoint() const noexcept;
    public:
        // Take ownership of map
        Instance(Map&& pmap);
        virtual ~Instance();

        void addPlayer(std::weak_ptr<Player> p, Point pt);
        size_t removePlayer(OID id);

        void generateMonsters(int n);

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

        bool walkable(int index) const noexcept;
        bool walkable(Point pt) const noexcept;

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}