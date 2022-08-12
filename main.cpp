
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include <instance.h>
#include <map.h>
#include <pathfinder.h>
#include <c_graphics.h>
#include <player.h>
#include <monster.h>

bool END = false;

class Test {
    const DR::Room& room;
};

using namespace std;
using namespace DR;

Pathfinder create_pathfinder(Instance* instance) {
    unsigned int width = instance->pmap.get_width();
    unsigned int height = instance->pmap.get_height();
	// Build pathfinder map
	unsigned int len = width * height;
	std::map<int, std::vector<int>> nodes;

	for (unsigned int i = 0; i < len; i++) {
		if (!instance->pmap.is_walkable(i)) {
			continue;;
		}

		std::vector<int> neighbors;

		// Up
		if (i - width >= 0 && instance->is_walkable(i - width)) {
			neighbors.push_back(i - width);
		}

		if (i + width < len && instance->is_walkable(i + width)) {
			neighbors.push_back(i + width);
		}

		if (i % width != 0 && instance->is_walkable(i - 1)) {
			neighbors.push_back(i - 1);
		}

		if (i % width != width - 1 && instance->is_walkable(i + 1)) {
			neighbors.push_back(i + 1);
		}

		if (!neighbors.empty()) {
			nodes[i] = neighbors;
		}
	}

	return Pathfinder(nodes);
}

PointPath find_path(Point src, Point dest, Pathfinder* pf, unsigned int width) {
    return PointPath(pf->find_path(src.index(width), dest.index(width)), src, dest, width);
}

void monster_thread(CGraphics* g, Player* p, Instance* inst, mutex* mu) {
    int i = 0;
    while (!END) {
        this_thread::sleep_for(chrono::milliseconds(500));

        auto now = chrono::steady_clock::now();
        for (pair<const OID, shared_ptr<Monster>>& pa : inst->monsters) {
            shared_ptr<Monster> me = pa.second;
            auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - me->get_last_moved());
            if (i_millis.count() <= me->get_speed()) {
                g->put("map", me->get_point(), 'M');
                continue;
            }

            lock_guard<mutex> lock(*mu);

            Pathfinder pf = create_pathfinder(inst);

            mvprintw(50 + (i % 5), 0, "%d - %d   ", i_millis.count(), me->get_speed());
            refresh();
            i++;
            me->set_last_moved(now);
			PointPath path = find_path(me->get_point(), p->get_point(), &pf, inst->pmap.get_width());

            if (path.empty()) {
                continue;
            }

            Point dest = path.pop();
            inst->cells.erase(me->get_point().index(inst->pmap.get_width()));
            inst->cells.insert({ dest.index(inst->pmap.get_width()), me });
            g->put("map", me->get_point(), inst->pmap.get_point(me->get_point()));
            me->set_point(dest);
            g->put("map", me->get_point(), 'M');
        }
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    Map m(OID::generate(), 150, 40, 7, 5);

    CGraphics c;
    c.addwin("map", { 0, 0, (int)m.get_width(), (int)m.get_height() });
    c.put_map("map", m, CGraphicsRoomConfig(), '#');

    Instance inst(move(m));
    inst.generate_monsters(25);

    Player p;
    Point pt = inst.rand_point();
    p.set_point(pt);

    //vector<Monster> monsters;
    // vector<thread> mts;
    mutex mu;


    //for (int i = 0; i < 10; i++) {
    //    Monster mo(OID::generate(), "Ice Monster");
    //    pt = m.rand_point();
    //    mo.set_point(pt);
    //    mo.set_last_moved(chrono::steady_clock::now());
    //    mo.set_speed(500 * (1 + rand() % 3));

    //    monsters.push_back(mo);
    //}

    thread mt(monster_thread, &c, &p, &inst, &mu);

    c.put("map", p.get_point(), '@');

    MEVENT e;
    int i;
    while ((i = c.cgetch("map")) != 'q') {
        Direction d = NONE;
        switch (i) {
        case 'a':
            d = LEFT;
            break;
        case 'd':
            d = RIGHT;
            break;
        case 's':
            d = DOWN;
            break;
        case 'w':
            d = UP;
            break;
        }

        if (d == NONE) {
            continue;
        }

        lock_guard<mutex> lock(mu);
        Point dest = p.get_point().move(d);
        if (!inst.is_walkable(dest)) {
            continue;
        }
        c.put("map", p.get_point(), inst.pmap.get_point(p.get_point()));
        p.set_point(dest);
        c.put("map", p.get_point(), '@');
    }

    END = true;
    mt.join();

    return 0;
}