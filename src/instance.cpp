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

DR::Instance::Instance(OID id, Map&& pmap) : id(id), pmap(std::move(pmap)) {}

DR::Instance::~Instance() {
}

DR::Point DR::Instance::randPoint() const noexcept {
    Point pt;
    do {
        pt = pmap.randPoint();
    } while (!walkable(pt));
    return pt;
}

void DR::Instance::addPlayer(std::shared_ptr<Player> p, Point pt) {
    players.insert({ p->getId(), p });
    uniqueCells.insert({ pt.index(pmap.getWidth()), p });
}

int DR::Instance::removePlayer(OID id) {
    auto p = players.find(id);
    if (p == players.end()) {
        return -1;
    }
    uniqueCells.erase(p->second->getPoint().index(pmap.getWidth()));
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

bool DR::Instance::move(std::shared_ptr<HasId> o, Point src, Point dest) {
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
    id.serialize(o);
    Serial playersJson;
    for (auto& p : players) {
        Serial playerJson;
        playerJson.put("id", p.second->getId().get());
        playersJson.push_back({ "", playerJson });
    }

    o.put_child("players", playersJson);

    Serial monstersJson;
    for (auto& m : monsters) {
        monstersJson.push_back({"", m.second->newSerialize()});
    }

    o.put_child("monsters", monstersJson);
    o.put_child("map", pmap.newSerialize());

    return o;
}

void DR::Instance::deserialize(const Serial& o) {
}