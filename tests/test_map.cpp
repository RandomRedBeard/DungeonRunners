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

void test_room() {
	Room r1({ 0, 0, 12, 12 });
	r1.setEa({ 2, 2 });
	Room r2({ 0, 0, 12, 12 });
	r2.setEa({ 2, 2 });
	assert(r1 == r2);
}

int main() {
	test_room();
	test_iter();
	return 0;
}