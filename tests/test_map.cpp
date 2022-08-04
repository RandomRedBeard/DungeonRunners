/**
 * @file test_map.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <assert.h>

#include <map.h>

using namespace std;
using namespace DR;

class Wrap {
	map<int, string> m;
public:
	void add(pair<int, string> p) {
		m.insert(p);
	}

	const map<int, string>& get() { return m; }

	map<int, string>::const_iterator find(int i) { return m.find(i); }
};

void test_iter() {
	Wrap w;
	w.add({ 1, "test" });

	const map<int, string>& m = w.get();
	map<int, string>::const_iterator iter = w.find(1);

	assert(iter != m.end());
}

void test_json() {
	srand(time(0));
	Map m(80, 25, 3, 3);
	json_t* o = m.new_json();

	Map m1 = Serializable::from_json<Map>(o);

	const std::map<int, Room>& m1_rooms = m1.get_rooms();
	std::map<int, Room>::const_iterator m1_end = m1_rooms.end();

	for (std::pair<int, Room> r : m.get_rooms()) {
		std::map<int, Room>::const_iterator iter = m1.find_room(r.first);
		if (m1_end == iter) {
			assert(0);
		}
		assert(iter != m1_rooms.end());
		assert(r.second == iter->second);
	}

	json_decref(o);
}

void test_room() {
	Room r1({ 0, 0, 12, 12 });
	r1.setEa({ 2, 2 });
	Room r2({ 0, 0, 12, 12 });
	r2.setEa({ 2, 2 });
	assert(r1 == r2);
}

int main() {
	test_json();
	test_room();
	test_iter();
	return 0;
}