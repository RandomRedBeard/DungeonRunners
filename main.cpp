
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include <map_pathfinder.h>
#include <instance.h>
#include <map.h>
#include <pathfinder.h>
#include <c_graphics.h>
#include <player.h>
#include <monster.h>

bool END = false;

using namespace std;
using namespace DR;

void monster_thread(CGraphics* g, Instance* inst, shared_ptr<Player> p, mutex* mu) {
    int i = 0;
    MapPathfinder pf(&inst->pmap);
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

            mvprintw(50 + (i % 5), 0, "%d - %d   ", i_millis.count(), me->get_speed());
            refresh();
            i++;
            me->set_last_moved(now);
            PointPath path = pf.find_path(me->get_point(), p->get_point());

            if (path.empty()) {
                continue;
            }

            Point dest = path.top();

            lock_guard<mutex> lock(*mu);
            if (!inst->move(me, me->get_point(), dest)) {
                continue;
            }
            path.pop();

            g->put("map", me->get_point(), inst->pmap.get_point(me->get_point()));
            me->set_point(dest);
            g->put("map", me->get_point(), 'M');
        }
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    Map m(OID::generate(), 150, 40, 7, 5);
    int width = m.get_width();
    int height = m.get_height();

    Instance inst(move(m));

    inst.generate_monsters(10);

    CGraphics c;
    c.addwin("map", { 0, 0, width, height });
    c.put_map("map", inst.pmap, CGraphicsRoomConfig(), '#');

    shared_ptr<Player> p = make_shared<Player>(OID::generate());
    Point pt = inst.rand_point();
    p->set_point(pt);
    inst.add_player(p, pt);

    mutex mu;

    thread mt(monster_thread, &c, &inst, p, &mu);

    c.put("map", p->get_point(), '@');

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
        Point dest = p->get_point().move(d);
        if (!inst.move(p, p->get_point(), dest)) {
            continue;
        }
        c.put("map", p->get_point(), inst.pmap.get_point(p->get_point()));
        p->set_point(dest);
        c.put("map", p->get_point(), '@');
    }

    END = true;
    mt.join();

    return 0;
}