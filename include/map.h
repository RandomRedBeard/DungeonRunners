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

namespace DR {

    const static char FLOOR = '.';
    const static char HALL = '#';
    const static char VWALL = '|';
    const static char HWALL = '-';
    const static char ENTR = '+';

    struct MapMeta {
        Room room;
        std::vector<Hallway> halls;
        char type;

        MapMeta(Room room) : room(room) {
            type = FLOOR;
        }

        MapMeta(Room room, char type) : room(room), type(type) {}

        MapMeta(Hallway hall) {
            halls.push_back(hall);
            type = HALL;
        }
    };

    class Map : public Serializable {
        // Phys-map attrs
        unsigned int width, height;
        // Room dims
        unsigned int rcols, rrows;

        // Physmap
        std::map<int, Room> rooms;
        std::vector<Hallway> halls;

        std::map<int, MapMeta> meta;

        // Valid move checking
        //std::unique_ptr<char[]> layout_bitmap;
        // Valid move checking 2.0 - Provide to others 
        //std::vector<int> cells;

        // Pathfinder
        Pathfinder pathfinder;

        /**
         * @brief Build layout
         *
         */
        void buildMeta();

        void buildPathfinder();
        Hallway buildHallway(Point pt1, Point pt2);
        void connectRooms();
        void buildMap();
    public:

        Map();
        Map(Map&& m) = default;
        Map& operator=(Map&& m) = default;
        Map(unsigned int width, unsigned int height, unsigned int rcols, unsigned int rrows);

        unsigned int getHeight() const noexcept { return height; }
        unsigned int getWidth() const noexcept { return width; }

        unsigned int getRrows() const noexcept { return rrows; }
        unsigned int getRcols() const noexcept { return rcols; }

        const std::map<int, Room>& getRooms() const noexcept { return rooms; }
        std::map<int, Room>::const_iterator findRoom(int index) { return rooms.find(index); }
        const std::vector<Hallway>& getHalls() const noexcept { return halls; }
        const std::map<int, MapMeta> getMeta() const noexcept { return meta; }
        const Pathfinder& getPathfinder() const noexcept { return pathfinder; }

        bool walkable(int index) const noexcept;
        bool walkable(Point pt) const noexcept;

        char getPoint(Point pt) const noexcept;

        /**
         * @brief Utility method for placing on map
         *
         * @return Point
         */
        Point randPoint() const noexcept;

        PointPath findPath(Point src, Point dest);

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
} // namespace DR
