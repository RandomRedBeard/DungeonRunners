
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include <map.h>
#include <pathfinder.h>
#include <c_graphics.h>
#include <player.h>
#include <monster.h>

bool END = false;

using namespace std;
using namespace DR;

void monster_thread(CGraphics* g, Map* m, Player* p, Monster* me, mutex* mu) {
    Map::MapPath path = m->find_path(me->get_point(), p->get_point());

    while (!END) {
        this_thread::sleep_for(chrono::seconds(1));

        if (path.empty()) {
            path = m->find_path(me->get_point(), p->get_point());
        }

        if (path.get_dest().dist(p->get_point()) > 3) {
            path = m->find_path(me->get_point(), p->get_point());
        }

        if (path.empty()) {
            continue;
        }

        lock_guard<mutex> lock(*mu);
        Point dest = path.pop();
        g->put("map", me->get_point(), m->get_point(me->get_point()));
        me->set_point(dest);
        g->put("map", me->get_point(), 'M');
    }
}

int main(int argc, char** argv) {

    srand(time(0));

    Map m(150, 40, 7, 5);

    CGraphics c;
    c.addwin("map", { 0, 0, (int)m.get_width(), (int)m.get_height() });

    c.put_map("map", m, CGraphicsRoomConfig(), '#');

    Player p;
    Point pt = m.rand_point();
    p.set_point(pt);

    vector<Monster*> monsters;
    vector<thread> mts;
    mutex mu;


    for (int i = 0; i < 10; i++) {
        Monster* mo = new Monster("Ice Monster");
        pt = m.rand_point();
        mo->set_point(pt);
        thread mt(monster_thread, &c, &m, &p, mo, &mu);

        monsters.push_back(mo);
        mts.push_back(move(mt));
    }

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

        Point dest = p.get_point().move(d);
        if (!m.is_walkable(dest)) {
            continue;
        }
        lock_guard<mutex> lock(mu);
        c.put("map", p.get_point(), m.get_point(p.get_point()));
        p.set_point(dest);
        c.put("map", p.get_point(), '@');
    }

    END = true;

    for (thread& i : mts) {
        i.join();
    }

    return 0;
}