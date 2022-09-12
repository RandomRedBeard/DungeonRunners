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

 // Do nothing for deserialization
DR::Instance::Instance() {}

DR::Instance::Instance(boost::uuids::uuid id, Map&& pmap) : id(id), pmap(std::move(pmap)) {}

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

int DR::Instance::removePlayer(boost::uuids::uuid id) {
    auto p = players.find(id);
    if (p == players.end()) {
        return -1;
    }
    uniqueCells.erase(p->second->getPoint().index(pmap.getWidth()));
    return players.erase(id);
}

void DR::Instance::addMonster(std::shared_ptr<Monster> m, Point pt) {
    monsters.insert({ m->getId(), m });
    uniqueCells.insert({ pt.index(pmap.getWidth()), m });
}

int DR::Instance::removeMonster(boost::uuids::uuid id) {
    auto m = monsters.find(id);
    if (m == monsters.end()) {
        return -1;
    }
    uniqueCells.erase(m->second->getPoint().index(pmap.getWidth()));
    return monsters.erase(id);
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

std::shared_ptr<DR::HasId> DR::Instance::getCell(int index) const noexcept {
    auto i = uniqueCells.find(index);
    if (i == uniqueCells.end()) {
        return std::shared_ptr<HasId>();
    }
    return i->second;
}

std::shared_ptr<DR::HasId> DR::Instance::getCell(Point pt) const noexcept {
    return getCell(pt.index(pmap.getWidth()));
}

DR::Serial DR::Instance::serialize(Serial& o) const noexcept {
    o.put("id", id);
    Serial playersJson;
    for (auto& p : players) {
        playersJson.push_back({ "", p.second->newSerialize() });
    }

    o.put_child("players", playersJson);

    Serial monstersJson;
    for (auto& m : monsters) {
        monstersJson.push_back({ "", m.second->newSerialize() });
    }

    o.put_child("monsters", monstersJson);
    o.put_child("map", pmap.newSerialize());

    return o;
}

void DR::Instance::deserialize(const Serial& o) {
    id = o.get<boost::uuids::uuid>("id");

    pmap.deserialize(o.get_child("map"));

    for (auto& p : o.get_child("players")) {
        std::shared_ptr<Player> player = std::make_shared<Player>();
        player->deserialize(p.second);
        players.insert({ player->getId(), player });
        uniqueCells.insert({ player->getPoint().index(pmap.getWidth()), player });
    }

    for (auto& m : o.get_child("monsters")) {
        std::shared_ptr<Monster> monster = std::make_shared<Monster>();
        monster->deserialize(m.second);
        monsters.insert({ monster->getId(), monster });
        uniqueCells.insert({ monster->getPoint().index(pmap.getWidth()), monster });
    }
}