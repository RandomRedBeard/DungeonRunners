/**
 * @file map.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

 // unique_ptr include
#include <memory>
#include <map>
#include <cstring>

#include <util.h>
#include <serializable.h>
#include <room.h>
#include <hallway.h>
#include <pathfinder.h>
#include <pointpath.h>
#include <oid.h>

namespace DR {

    class Map : public Serializable {
        OID id;
        // Phys-map attrs
        unsigned int width, height;
        // Room dims
        unsigned int rcols, rrows;

        // Physmap
        std::map<int, Room> rooms;
        std::vector<Hallway> halls;

        // Valid move checking
        std::unique_ptr<char[]> layout_bitmap;
        // Valid move checking 2.0 - Provide to others 
        std::vector<int> cells;

        // Pathfinder
        Pathfinder pathfinder;

        /**
         * @brief Builds layout_bitmap and cells
         *
         */
        void build_layout_bitmap();

        void build_pathfinder();
        Hallway build_hallway(Point pt1, Point pt2);
        void connect_rooms();
        void build_map();
    public:
        const static char FLOOR = '.';
        const static char HALL = '#';
        const static char VWALL = '|';
        const static char HWALL = '-';
        const static char ENTR = '+';

        Map();
        Map(Map&& m) = default;
        Map(OID id, unsigned int width, unsigned int height, unsigned int rcols, unsigned int rrows);
        virtual ~Map();

        const OID get_id() { return id; }

        unsigned int get_height() { return height; }
        unsigned int get_width() { return width; }

        unsigned int get_rrows() { return rrows; }
        unsigned int get_rcols() { return rcols; }

        const std::map<int, Room>& get_rooms() const noexcept { return rooms; }
        std::map<int, Room>::const_iterator find_room(int index) { return rooms.find(index); }
        const std::vector<Hallway>& get_halls() const noexcept { return halls; }
        const Pathfinder& get_pathfinder() const noexcept { return pathfinder; }

        bool is_walkable(int index) const noexcept;
        bool is_walkable(Point pt) const noexcept;

        char get_point(Point pt) const noexcept;

        const std::vector<int> get_cells() const noexcept { return cells; }

        /**
         * @brief Utility method for placing on map
         *
         * @return Point
         */
        Point rand_point() const noexcept;

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);

        PointPath find_path(Point src, Point dest);
    };
} // namespace DR
