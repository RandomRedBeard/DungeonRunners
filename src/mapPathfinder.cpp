/**
 * @file map_pathfinder.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "mapPathfinder.h"

DR::MapPathfinder::MapPathfinder(const Map* m) : width(m->getWidth()) {
    auto rng = std::default_random_engine{};
    unsigned int height = m->getHeight();
    // Build pathfinder map
    unsigned int len = width * height;
    std::map<int, std::vector<int>> nodes;

    for (unsigned int i = 0; i < len; i++) {
        if (!m->walkable(i)) {
            continue;;
        }

        std::vector<int> neighbors;

        // Up
        if (i - width >= 0 && m->walkable(i - width)) {
            neighbors.push_back(i - width);
        }

        if (i + width < len && m->walkable(i + width)) {
            neighbors.push_back(i + width);
        }

        if (i % width != 0 && m->walkable(i - 1)) {
            neighbors.push_back(i - 1);
        }

        if (i % width != width - 1 && m->walkable(i + 1)) {
            neighbors.push_back(i + 1);
        }

        if (!neighbors.empty()) {
            // A little bit of spice
            std::shuffle(std::begin(neighbors), std::end(neighbors), rng);
            nodes[i] = neighbors;
        }
    }

    pf = Pathfinder(nodes);
}

DR::PointPath DR::MapPathfinder::findPath(Point src, Point dest) {
    return PointPath(pf.findPath(src.index(width), dest.index(width)), src, dest, width);
}