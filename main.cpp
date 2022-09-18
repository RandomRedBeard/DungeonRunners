/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

#include <message.h>
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

boost::uuids::random_generator idGen;

void generateMonsters(int n, Instance* ins) {
    for (int i = 0; i < n; i++) {
        std::shared_ptr<Monster> m = std::make_shared<Monster>(idGen(), "Ice Monster");
        Point pt = ins->randPoint();
        m->setPoint(pt);
        m->setLastMoved(std::chrono::steady_clock::now());
        m->setSpeed(500 * (1 + rand() % 3));
        m->setHealth(10);

        ins->addMonster(m, pt);
    }
}

void monsterThread(CGraphics* g, Instance* inst, shared_ptr<Player> p, mutex* mu) {
    const Map* pmap = inst->getMap();
    int i = 0;
    MapPathfinder pf(pmap);
    while (!END) {
        this_thread::sleep_for(chrono::milliseconds(500));
        auto now = chrono::steady_clock::now();
        lock_guard<mutex> lock(*mu);

        if (!p->isAlive()) {
            continue;
        }

        for (auto& pa : inst->getMonsters()) {
            shared_ptr<Monster> me = pa.second;
            auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(now - me->getLastMoved());
            if (!me->isAlive()) {
                g->put("map", me->getPoint(), 'D');
                continue;
            }
            if (i_millis.count() <= me->getSpeed()) {
                g->put("map", me->getPoint(), 'M');
                continue;
            }

            me->setLastMoved(now);
            PointPath path = pf.findPath(me->getPoint(), p->getPoint());

            if (path.empty()) {
                g->log("Empty Path %d", me->getPoint().l1dist(p->getPoint()));
                continue;
            }

            Point dest = path.top();
            auto cell = inst->getCell(dest);
            if (cell) {
                shared_ptr<Player> target = std::dynamic_pointer_cast<Player>(cell);
                if (target) {
                    target->takeDamage(2);
                    g->log("Player %s %d(%d)", boost::uuids::to_string(target->getId()).c_str(), target->getHealth(), target->getMaxHealth());
                    g->putHUD("map", p);
                }
                continue;
            }

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

    Instance inst(idGen(), Map(parser.getLong("w"), parser.getLong("h"), parser.getLong("cc"), parser.getLong("rc")));

    const Map* pmap = inst.getMap();
    int width = pmap->getWidth();
    int height = pmap->getHeight();

    generateMonsters(parser.getLong("mc"), &inst);

    CGraphics c;
    c.addwin("map", { 0, 0, width, height });
    c.setLogger({ 0, height, width, 20 });
    c.putMap("map", *pmap, CGraphicsRoomConfig(), '#');

    shared_ptr<Player> p = make_shared<Player>(idGen());
    p->setName("Player");
    p->setHealth(10);
    Point pt = inst.randPoint();
    p->setPoint(pt);
    inst.addPlayer(p, pt);

    mutex mu;

    thread mt(monsterThread, &c, &inst, p, &mu);

    c.put("map", p->getPoint(), '@');
    c.putHUD("map", p);

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
        case ' ':
            p->setHealth(10);
            break;
        }

        if (d == NONE) {
            continue;
        }

        lock_guard<mutex> lock(mu);

        if (!p->isAlive()) {
            c.log("You are dead");
            continue;
        }
        
        Point dest = p->getPoint().move(d);
        auto cell = inst.getCell(dest);
        if (cell) {
            shared_ptr<Monster> target = std::dynamic_pointer_cast<Monster>(cell);
            if (target) {
                target->takeDamage(2);
                if (!target->isAlive()) {
                    inst.removeMonster(target->getId());
                }
                c.log("Monster %s %d(%d)", boost::uuids::to_string(target->getId()).c_str(), target->getHealth(), target->getMaxHealth());
                continue;
            }
        }

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