/**
 * @file pathfinder.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "pathfinder.h"

DR::Pathfinder::Pathfinder() {}

DR::Pathfinder::Pathfinder(const T& nodes) : nodes(nodes) {}

std::stack<int> DR::Pathfinder::findPath(int src, int dest) const noexcept {
    if (src == dest) {
        return std::stack<int>();
    }
    // visited bit map len
    unsigned int vlen = (nodes.rbegin()->first / 8) + 1;
    // visited bit map
    std::unique_ptr<char[]> v = std::make_unique<char[]>(vlen);
    // processing queue
    std::queue<int> q;
    // Result mapping 
    std::map<int, int> rmap;
    // src to dest path
    std::stack<int> rpath;

    bool found = false;

    q.push(src);
    flipBit(v.get(), src);

    while (!q.empty()) {
        int i = q.front();
        if (i == dest) {
            found = true;
            break;
        }

        auto iter = nodes.find(i);
        // Should never happen
        if (iter == nodes.end()) {
            q.pop();
            continue;
        }

        for (int n : iter->second) {
            // Skip if node has been visited
            if (isBitFlipped(v.get(), n)) {
                continue;
            }

            rmap[n] = i;
            flipBit(v.get(), n);
            q.push(n);
        }

        q.pop();
    }

    if (!found) {
        return rpath;
    }

    // fill out rpath
    int i = dest;
    while (i != src) {
        rpath.push(i);
        i = rmap[i];
    }

    return rpath;
}