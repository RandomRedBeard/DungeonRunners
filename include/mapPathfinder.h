/**
 * @file map_pathfinder.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <algorithm>
#include <random>

#include <map.h>
#include <pathfinder.h>
#include <pointpath.h>

namespace DR {
    class MapPathfinder {
        unsigned int width;
        Pathfinder pf;
    public:
        MapPathfinder(const Map* m);

        PointPath findPath(Point src, Point dest);
    };
}