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

DR::Point DR::Instance::rand_point() const noexcept {
    Point pt;
    do {
        pt = pmap.rand_point();
    } while (!is_walkable(pt));
    return pt;
}

void DR::Instance::add_player(std::weak_ptr<Player> p, Point pt) {
    auto l = p.lock();
    players.insert({l->get_id(), p});
    unique_cells.insert({ pt.index(pmap.get_width()), p });
}

void DR::Instance::generate_monsters(int n) {
    for (int i = 0; i < n; i++) {
        std::shared_ptr<Monster> m = std::make_shared<Monster>(OID::generate(), "Ice Monster");
        Point pt = rand_point();
        m->set_point(pt);
        m->set_last_moved(std::chrono::steady_clock::now());
        m->set_speed(500 * (1 + rand() % 3));

        // Add to containers
        monsters.insert({ m->get_id(), m });
        unique_cells.insert({ pt.index(pmap.get_width()), m });
    }
}

bool DR::Instance::move(std::weak_ptr<HasId> o, Point src, Point dest) {
    if (!is_walkable(dest)) {
        return false;
    }

    unique_cells.erase(src.index(pmap.get_width()));
    unique_cells.insert({ dest.index(pmap.get_width()), o });
    return true;
}

bool DR::Instance::is_walkable(int index) const noexcept {
    return pmap.is_walkable(index) && unique_cells.find(index) == unique_cells.end();
}

bool DR::Instance::is_walkable(Point pt) const noexcept {
    return is_walkable(pt.index(pmap.get_width()));
}