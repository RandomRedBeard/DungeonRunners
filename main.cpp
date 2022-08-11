
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

void monster_thread(CGraphics* g, Map* m, Player* p, std::vector<Monster>* monsters, mutex* mu) {
    int i = 0;
    while (!END) {
        this_thread::sleep_for(chrono::milliseconds(500));
        auto now = chrono::steady_clock::now();
        for (Monster& me : *monsters) {
            auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - me.get_last_moved());
            if (i_millis.count() <= me.get_speed()) {
                continue;
            }

            mvprintw(50 + (i % 5), 0, "%d - %d   ", i_millis.count(), me.get_speed());
            refresh();
            i++;
            me.set_last_moved(now);
            PointPath path = m->find_path(me.get_point(), p->get_point());

            if (path.empty()) {
                continue;
            }

            lock_guard<mutex> lock(*mu);
            Point dest = path.pop();
            g->put("map", me.get_point(), m->get_point(me.get_point()));
            me.set_point(dest);
            g->put("map", me.get_point(), 'M');
        }
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    Map m(OID::generate(), 150, 40, 7, 5);

    CGraphics c;
    c.addwin("map", { 0, 0, (int)m.get_width(), (int)m.get_height() });
    c.put_map("map", m, CGraphicsRoomConfig(), '#');

    Player p;
    Point pt = m.rand_point();
    p.set_point(pt);

    vector<Monster> monsters;
    vector<Monster&> refs;
    // vector<thread> mts;
    mutex mu;


    for (int i = 0; i < 10; i++) {
        Monster mo("Ice Monster");
        pt = m.rand_point();
        mo.set_point(pt);
        mo.set_last_moved(chrono::steady_clock::now());
        mo.set_speed(500 * (1 + rand() % 3));

        monsters.push_back(mo);
        refs.push_back(*(monsters.end() - 1));
    }

    thread mt(monster_thread, &c, &m, &p, &monsters, &mu);

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
    mt.join();

    return 0;
}