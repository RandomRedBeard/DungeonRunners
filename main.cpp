
#include <iostream>

#include <map.h>
#include <pathfinder.h>
#include <c_graphics.h>
#include <player.h>

using namespace std;
using namespace DR;

int main(int argc, char** argv) {

    srand(time(0));

    Map m(150, 40, 7, 5);

    unsigned int width = m.get_width();
    // const Pathfinder p = m.get_pathfinder();
    // Room src_room = m.get_rooms().begin()->second;
    // Point src(src_room.x + 1, src_room.y + 1);

    CGraphics c;
    c.addwin("map", { 0, 0, (int)m.get_width(), (int)m.get_height() });

    c.put_map("map", m, CGraphicsRoomConfig(), '#');

    Player p;
    Point pt = m.get_rooms().begin()->second.rand_point();
    p.set_point(pt);

    c.put("map", p.get_point(), '@');

    int i;
    while ((i = c.cgetch("map")) != 'q') {
        Direction d;
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

        Point dest = p.get_point().move(d);
        if (!m.is_walkable(dest)) {
            continue;
        }

        c.put("map", p.get_point(), m.get_point(p.get_point()));
        p.set_point(dest);
        c.put("map", p.get_point(), '@');
    }

    // int ch = c.cgetch("map");
    // if (ch != KEY_MOUSE) {
    //     printw("Not mouse %d", ch);
    //     getch();
    //     return -1;
    // }

    // MEVENT event;
    // if (getmouse(&event) != OK) {
    //     printw("Failed to get mouse");
    //     getch();
    //     return -1;
    // }

    // Point dest(event.x, event.y);

    // vector<int> rpath = p.find_path(src.index(width), dest.index(width));

    // c.put("map", src, 'S');
    // c.put("map", dest, 'D');

    // for (int i : rpath) {
    //     if (i == src.index(width) || i == dest.index(width)) {
    //         continue;
    //     }
    //     c.put("map", Point::index(i, width), '*');
    // }

    // getch();

    return 0;
}