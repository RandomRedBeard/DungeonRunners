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
#include <mapPathfinder.h>

namespace DR {
    /**
     * @brief A single map instance
     *
     */
    class Instance : public Serializable {
        boost::uuids::uuid id;
        // DMLayer will not own players
        std::map<boost::uuids::uuid, std::shared_ptr<Player>> players;
        // This will own the monsters and map
        std::map<boost::uuids::uuid, std::shared_ptr<Monster>> monsters;
        Map pmap;

        // Map for unique cell placement
        // Weak pointer for non-owning
        std::map<int, std::shared_ptr<HasId>> uniqueCells;
    public:
        Instance();
        // Take ownership of map
        Instance(boost::uuids::uuid id, Map&& pmap);
        Instance(Instance&& instance) = default;
        Instance& operator=(Instance&& instance) = default;
        virtual ~Instance();

        const boost::uuids::uuid getId() const noexcept { return id; }

        void addPlayer(std::shared_ptr<Player> p, Point pt);
        int removePlayer(boost::uuids::uuid id);
        const std::map<boost::uuids::uuid, std::shared_ptr<Player>>& getPlayers() const noexcept { return players; }

        void addMonster(std::shared_ptr<Monster> m, Point pt);
        int removeMonster(boost::uuids::uuid id);
        const std::map<boost::uuids::uuid, std::shared_ptr<Monster>>& getMonsters() const noexcept { return monsters; }


        /**
         * @brief pmap.rand_point + unique_cell consideration
         *
         * @return Point
         */
        Point randPoint() const noexcept;

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
        bool move(std::shared_ptr<HasId> o, Point src, Point dest);

        bool walkable(int index) const noexcept;
        bool walkable(Point pt) const noexcept;

        std::shared_ptr<HasId> getCell(int index) const noexcept;
        std::shared_ptr<HasId> getCell(Point pt) const noexcept;

        const Map* getMap() const noexcept { return &pmap; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}