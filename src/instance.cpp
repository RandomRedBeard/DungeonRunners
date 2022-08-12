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

DR::Point DR::Instance::rand_point() {
	Point pt;
	do {
		pt = pmap.rand_point();
	} while (cells.find(pt.index(pmap.get_width())) != cells.end());
	return pt;
}

bool DR::Instance::is_walkable(int index) {
	return pmap.is_walkable(index) && cells.find(index) == cells.end();
}

bool DR::Instance::is_walkable(DR::Point pt) {
	return is_walkable(pt.index(pmap.get_width()));
}

void DR::Instance::generate_monsters(int n) {
	for (int i = 0; i < n; i++) {
		std::shared_ptr<Monster> m = std::make_shared<Monster>(OID::generate(), "Ice Monster");
		Point pt = rand_point();
		m->set_point(pt);
	    m->set_last_moved(std::chrono::steady_clock::now());
		m->set_speed(500 * (1 + rand() % 3));
		cells.insert({ pt.index(pmap.get_width()), m });
		monsters.insert({ m->get_id(), m });
	}
}