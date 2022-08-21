/**
 * @file c_graphic.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "cGraphics.h"

DR::CGraphics::CGraphics() {
    initscr();
    clear();
    noecho();
    cbreak();
    refresh();
    start_color();
    use_default_colors();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    windows.insert({ CGRAPHICS_STDSCR, stdscr });
}

DR::CGraphics::~CGraphics() {
    for (std::pair<std::string, WINDOW*> p : windows) {
        if (p.first == CGRAPHICS_STDSCR) {
            continue;
        }
        delwin(p.second);
    }
    endwin();
}

int DR::CGraphics::addwin(std::string win, const Rect r) {
    if (windows.find(win) != windows.end()) {
        return -1;
    }
    WINDOW* w = newwin(r.h, r.w, r.y, r.x);
    keypad(w, TRUE);
    box(w, 0, 0);
    windows.insert({ win, w });
    return 0;
}

int DR::CGraphics::put(WINDOW* win, const Point pt, char c) {
    int x, y, i;
    getyx(win, x, y);
    i = mvwaddch(win, pt.y, pt.x, c);
    wmove(win, x, y);
    wrefresh(win);
    return i;
}

int DR::CGraphics::put(std::string win, const Point pt, char c) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return put(iter->second, pt, c);
}

int DR::CGraphics::put(WINDOW* win, const Rect r, const CGraphicsRectConfig cfg) {
    for (int i = 1; i < r.w - 1; i++) {
        for (int j = 1; j < r.h - 1; j++) {
            put(win, { i + r.x, j + r.y }, cfg.floor);
        }
    }

    // Ceilings are one above
    for (int i = 1; i < r.h - 1; i++) {
        put(win, { r.x, i + r.y }, cfg.hwall);
        put(win, { r.x + r.w - 1, i + r.y }, cfg.hwall);
    }

    for (int i = 0; i < r.w; i++) {
        put(win, { r.x + i, r.y }, cfg.vwall);
        put(win, { r.x + i, r.y + r.h - 1 }, cfg.vwall);
    }

    return 0;
}

int DR::CGraphics::put(std::string win, const Rect r, const CGraphicsRectConfig cfg) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return put(iter->second, r, cfg);
}

int DR::CGraphics::putRoom(WINDOW* win, const Room r, const CGraphicsRoomConfig cfg) {
    put(win, r, cfg);
    if (r.getEa().x > 0) {
        put(win, r.getEa(), cfg.entr);
    }

    if (r.getSo().x > 0) {
        put(win, r.getSo(), cfg.entr);
    }

    if (r.getWe().x > 0) {
        put(win, r.getWe(), cfg.entr);
    }

    if (r.getNo().x > 0) {
        put(win, r.getNo(), cfg.entr);
    }

    return 0;
}

int DR::CGraphics::putRoom(std::string win, const Room r, const CGraphicsRoomConfig cfg) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return putRoom(iter->second, r, cfg);
}

int DR::CGraphics::putHallway(WINDOW* win, const Hallway h, char c) {
    for (Point pt : h.getPoints()) {
        put(win, pt, c);
    }

    return 0;
}

int DR::CGraphics::putHallway(std::string win, const Hallway h, char c) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return putHallway(iter->second, h, c);
}

int DR::CGraphics::putMap(WINDOW* win, const Map& m, const CGraphicsRoomConfig cfg, char c) {
    for (std::pair<int, Room> r : m.getRooms()) {
        putRoom(win, r.second, cfg);
    }

    for (Hallway h : m.getHalls()) {
        putHallway(win, h, c);
    }

    return 0;
}

int DR::CGraphics::putMap(std::string win, const Map& m, const CGraphicsRoomConfig cfg, char c) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return putMap(iter->second, m, cfg, c);
}


int DR::CGraphics::cgetch(std::string win) {
    std::map<std::string, WINDOW*>::iterator iter = windows.find(win);
    if (iter == windows.end()) {
        return -1;
    }

    return wgetch(iter->second);
}
