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

#include "map_pathfinder.h"

DR::MapPathfinder::MapPathfinder(const Map* m) : width(m->get_width()) {
    auto rng = std::default_random_engine{};
    unsigned int height = m->get_height();
    // Build pathfinder map
    unsigned int len = width * height;
    std::map<int, std::vector<int>> nodes;

    for (unsigned int i = 0; i < len; i++) {
        if (!m->is_walkable(i)) {
            continue;;
        }

        std::vector<int> neighbors;

        // Up
        if (i - width >= 0 && m->is_walkable(i - width)) {
            neighbors.push_back(i - width);
        }

        if (i + width < len && m->is_walkable(i + width)) {
            neighbors.push_back(i + width);
        }

        if (i % width != 0 && m->is_walkable(i - 1)) {
            neighbors.push_back(i - 1);
        }

        if (i % width != width - 1 && m->is_walkable(i + 1)) {
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

DR::PointPath DR::MapPathfinder::find_path(Point src, Point dest) {
    return PointPath(pf.find_path(src.index(width), dest.index(width)), src, dest, width);
}