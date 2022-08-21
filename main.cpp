
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include <arg.h>
#include <mapPathfinder.h>
#include <instance.h>
#include <map.h>
#include <pathfinder.h>
#include <cGraphics.h>
#include <player.h>
#include <monster.h>

bool END = false;

using namespace std;
using namespace DR;

void monsterThread(CGraphics* g, Instance* inst, shared_ptr<Player> p, mutex* mu) {
    const Map* pmap = inst->getMap();
    int i = 0;
    MapPathfinder pf(pmap);
    while (!END) {
        this_thread::sleep_for(chrono::milliseconds(500));
        auto now = chrono::steady_clock::now();
        for (auto& pa : inst->getMonsters()) {
            shared_ptr<Monster> me = pa.second;
            auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - me->getLastMoved());
            if (i_millis.count() <= me->getSpeed()) {
                g->put("map", me->getPoint(), 'M');
                continue;
            }

            mvprintw(pmap->getHeight() + (i % 10), 0, "%s - %d - %d   ", me->getId().get().c_str(), i_millis.count(), me->getSpeed());
            refresh();
            i++;
            me->setLastMoved(now);
            PointPath path = pf.findPath(me->getPoint(), p->getPoint());

            if (path.empty()) {
                continue;
            }

            Point dest = path.top();

            lock_guard<mutex> lock(*mu);
            if (!inst->move(me, me->getPoint(), dest)) {
                continue;
            }
            path.pop();

            g->put("map", me->getPoint(), pmap->getPoint(me->getPoint()));
            me->setPoint(dest);
            g->put("map", me->getPoint(), 'M');
        }
    }
}

int main(int argc, char** argv) {
    srand(time(0));

    ArgParser parser;
    parser.addLong("w", 150);
    parser.addLong("h", 40);
    parser.addLong("cc", 3);
    parser.addLong("rc", 3);
    parser.addLong("mc", 10);

    parser.parse(argc, argv);

    Instance inst(OID::generate(), Map(parser.getLong("w"), parser.getLong("h"), parser.getLong("cc"), parser.getLong("rc")));

    const Map* pmap = inst.getMap();
    int width = pmap->getWidth();
    int height = pmap->getHeight();

    inst.generateMonsters(parser.getLong("mc"));

    CGraphics c;
    c.addwin("map", { 0, 0, width, height });
    c.putMap("map", *pmap, CGraphicsRoomConfig(), '#');

    shared_ptr<Player> p = make_shared<Player>(OID::generate());
    Point pt = inst.randPoint();
    p->setPoint(pt);
    inst.addPlayer(p, pt);

    mutex mu;

    thread mt(monsterThread, &c, &inst, p, &mu);

    c.put("map", p->getPoint(), '@');

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
        Point dest = p->getPoint().move(d);
        if (!inst.move(p, p->getPoint(), dest)) {
            continue;
        }
        c.put("map", p->getPoint(), pmap->getPoint(p->getPoint()));
        p->setPoint(dest);
        c.put("map", p->getPoint(), '@');
    }

    END = true;
    mt.join();

    return 0;
}