/**
 * @file instance.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "instance.h"

DR::Instance::Instance(DR::Map&& pmap) : pmap(std::move(pmap)) {}

DR::Instance::~Instance() {
}

DR::Point DR::Instance::randPoint() const noexcept {
    Point pt;
    do {
        pt = pmap.randPoint();
    } while (!walkable(pt));
    return pt;
}

void DR::Instance::addPlayer(std::weak_ptr<Player> p, Point pt) {
    auto l = p.lock();
    players.insert({ l->getId(), p });
    uniqueCells.insert({ pt.index(pmap.getWidth()), p });
}

size_t DR::Instance::removePlayer(OID id) {
    return players.erase(id);
}

void DR::Instance::generateMonsters(int n) {
    for (int i = 0; i < n; i++) {
        std::shared_ptr<Monster> m = std::make_shared<Monster>(OID::generate(), "Ice Monster");
        Point pt = randPoint();
        m->setPoint(pt);
        m->setLastMoved(std::chrono::steady_clock::now());
        m->setSpeed(500 * (1 + rand() % 3));

        // Add to containers
        monsters.insert({ m->getId(), m });
        uniqueCells.insert({ pt.index(pmap.getWidth()), m });
    }
}

bool DR::Instance::move(std::weak_ptr<HasId> o, Point src, Point dest) {
    if (!walkable(dest)) {
        return false;
    }

    uniqueCells.erase(src.index(pmap.getWidth()));
    uniqueCells.insert({ dest.index(pmap.getWidth()), o });
    return true;
}

bool DR::Instance::walkable(int index) const noexcept {
    return pmap.walkable(index) && uniqueCells.find(index) == uniqueCells.end();
}

bool DR::Instance::walkable(Point pt) const noexcept {
    return walkable(pt.index(pmap.getWidth()));
}

DR::Serial DR::Instance::serialize(Serial& o) const noexcept {
    return o;
}

void DR::Instance::deserialize(const Serial& o) {
    
}