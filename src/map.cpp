/**
 * @file map.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "map.h"

DR::Map::Map() {}

DR::Map::Map(OID id, unsigned int width, unsigned int height, unsigned int rcols, unsigned int rrows) : id(id), width(width), height(height), rcols(rcols), rrows(rrows) {
    buildMap();
    connectRooms();
    buildMeta();
}

DR::Map::~Map() {
}

void DR::Map::buildMeta() {
    unsigned int len = width * height;

    for (std::pair<int, Room> p : rooms) {
        Room r = p.second;
        for (int i = 1; i < r.w - 1; i++) {
            for (int j = 1; j < r.h - 1; j++) {
                int pt = Point::index(i + r.x, j + r.y, width);
                meta.insert({ pt, MapMeta(r) });
            }
        }

        if (r.getEa().x > 0) {
            int pt = r.getEa().index(width);
            meta.insert({ pt, MapMeta(r, ENTR) });
        }

        if (r.getSo().x > 0) {
            int pt = r.getSo().index(width);
            meta.insert({ pt, MapMeta(r, ENTR) });

        }

        if (r.getWe().x > 0) {
            int pt = r.getWe().index(width);
            meta.insert({ pt, MapMeta(r, ENTR) });

        }

        if (r.getNo().x > 0) {
            int pt = r.getNo().index(width);
            meta.insert({ pt, MapMeta(r, ENTR) });

        }
    }

    for (Hallway h : halls) {
        for (Point p : h.getPoints()) {
            int pt = p.index(width);
            meta.insert({ pt, MapMeta(h) });
        }
    }
}

DR::Hallway DR::Map::buildHallway(Point pt1, Point pt2) {
    int xleft = std::abs(pt1.x - pt2.x), yleft = std::abs(pt1.y - pt2.y);
    int xdir = 0, ydir = 0, dir;
    Point index = pt1;
    Hallway h;

    if (pt1.x < pt2.x) {
        xdir = 1;
    }
    else if (pt1.x > pt2.x) {
        xdir = -1;
    }

    if (pt1.y < pt2.y) {
        ydir = 1;
    }
    else if (pt1.y > pt2.y) {
        ydir = -1;
    }

    while (index != pt2) {
        h.addPoint(index);

        if (xleft > std::rand() % (yleft + 1)) {
            dir = 0;
        }
        else {
            dir = 1;
        }

        if (dir == 0) {
            index.x += xdir;
            xleft--;
        }
        else if (dir == 1) {
            index.y += ydir;
            yleft--;
        }
    }

    h.addPoint(index);
    return h;
}

void DR::Map::connectRooms() {
    // Iter by ref
    for (std::pair<const int, DR::Room>& r : rooms) {
        int index = r.first;
        // Reference
        Room& src = r.second;
        /**
         * @brief Check to the right
         *
         */
        for (unsigned int i = 1; i < rcols - (index % rcols); i++) {
            int search_index = index + i;
            std::map<int, Room>::iterator iter = rooms.find(search_index);
            // Room not found
            if (iter == rooms.end()) {
                continue;
            }

            // Grab ref
            Room& dest = iter->second;

            // Set entrances
            src.setEa({ src.x + src.w - 1, src.y + 1 + std::rand() % (src.h - 2) });
            dest.setWe({ dest.x, dest.y + 1 + std::rand() % (dest.h - 2) });

            // Build hallway
            Point ea = src.getEa(), we = dest.getWe();
            Hallway h = buildHallway({ ea.x + 1, ea.y }, { we.x - 1, we.y });
            halls.push_back(h);

            break;
        }

        /**
         * @brief Check below
         *
         */
        for (unsigned int i = 1; i < rrows - (index / rcols); i++) {
            int search_index = index + (i * rcols);
            std::map<int, Room>::iterator iter = rooms.find(search_index);
            // Room not found
            if (iter == rooms.end()) {
                continue;
            }

            // Grab ref
            Room& dest = iter->second;

            // Set entrances
            src.setSo({ src.x + 1 + std::rand() % (src.w - 2), src.y + src.h - 1 });
            dest.setNo({ dest.x + 1 + std::rand() % (dest.w - 2), dest.y });

            // Build hallway
            Point so = src.getSo(), no = dest.getNo();
            Hallway h = buildHallway({ so.x, so.y + 1 }, { no.x, no.y - 1 });
            halls.push_back(h);

            break;
        }
    }
}

void DR::Map::buildMap() {
    unsigned int maxrw = width / rcols;
    unsigned int maxrh = height / rrows;
    unsigned int rcount = rrows * rcols;

    int numberOfAllowed = ((rrows - 1) * (rcols - 1)) + 2;
    int numberAllowedFalse = rcount - numberOfAllowed;

    /**
     * @brief Build rooms
     *
     */
    for (unsigned int i = 0; i < rrows; i++) {
        for (unsigned int j = 0; j < rcols; j++) {
            int index = i * rcols + j;
            if (prob(numberAllowedFalse / (rcount * 1.0))) {
                numberAllowedFalse--;
                continue;
            }

            Point p(4 + std::rand() % (maxrw - 6), 4 + std::rand() % (maxrh - 6));

            int tmidptw = maxrw * j;
            int tmidpth = maxrh * i;
            int wdel = maxrw - p.x;
            int hdel = maxrh - p.y;

            Point tl(tmidptw + (1 + std::rand() % (wdel - 2)), tmidpth + (1 + std::rand() % (hdel - 2)));

            Room r({ tl.x, tl.y, p.x, p.y });
            rooms.insert({ index, r });
        }
    }
}

bool DR::Map::walkable(int index) const noexcept {
    return meta.find(index) != meta.end();
}


bool DR::Map::walkable(Point pt) const noexcept {
    return walkable(pt.index(width));
}

char DR::Map::getPoint(Point pt) const noexcept {
    auto iter = meta.find(pt.index(width));
    return iter == meta.end() ? ' ' : iter->second.type;
}

DR::Point DR::Map::randPoint() const noexcept {
    auto it = rooms.begin();
    std::advance(it, std::rand() % rooms.size());
    Room r = it->second;
    return r.randPoint();
}

DR::Serial DR::Map::serialize(Serial& o) const noexcept {
    id.serialize(o);
    o.put("width", width);
    o.put("height", height);
    o.put("rcols", rcols);
    o.put("rrows", rrows);

    Serial roomsJson;
    for (auto& p : rooms) {
        Serial roomInst;
        roomInst.put("index", p.first);
        roomInst.put_child("room", p.second.newSerialize());
        roomsJson.push_back({ "", roomInst });
    }

    o.put_child("rooms", roomsJson);

    Serial hallsJson;
    for (auto& p : halls) {
        hallsJson.push_back({ "", p.newSerialize() });
    }

    o.put_child("halls", hallsJson);

    return o;
}

void DR::Map::deserialize(const Serial& o) {
    id.deserialize(o);
    width = o.get<int>("width");
    height = o.get<int>("height");
    rcols = o.get<int>("rcols");
    rrows = o.get<int>("rrows");

    for (auto& p : o.get_child("rooms")) {
        Room r;
        int index = p.second.get<int>("index");
        r.deserialize(p.second.get_child("room"));
        rooms.insert({ index, r });
    }

    for (auto& p : o.get_child("halls")) {
        Hallway h;
        h.deserialize(p.second);
        halls.push_back(h);
    }
}