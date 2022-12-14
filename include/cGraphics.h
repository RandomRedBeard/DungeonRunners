/**
 * @file c_graphic.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>
#include <map>
#include <mutex>

#include <curses.h>

#include <point.h>
#include <rect.h>
#include <room.h>
#include <map.h>
#include <hallway.h>
#include <player.h>

#define CGRAPHICS_STDSCR "stdscr"

namespace DR {

    struct CGraphicsRectConfig {
        char hwall = '|', vwall = '-', floor = '.';
    };

    struct CGraphicsRoomConfig : public CGraphicsRectConfig {
        char entr = '+';
    };

    /**
     * @brief Curses style graphics
     *
     */
    class CGraphics {
        std::map<std::string, WINDOW*> windows;
        std::mutex lock;
        WINDOW* logger;
        int put(WINDOW* win, const Point pt, char c);
        int put(WINDOW* win, const Rect r, const CGraphicsRectConfig cfg);
        int putRoom(WINDOW* win, const Room r, const CGraphicsRoomConfig cfg);
        int putHallway(WINDOW* win, const Hallway h, char c);
        int putMap(WINDOW* win, const Map& m, const CGraphicsRoomConfig cfg, char c);
    public:
        CGraphics();
        CGraphics(const CGraphics& c) = delete;
        CGraphics(CGraphics&& c) = delete;
        virtual ~CGraphics();
        int addwin(std::string win, const Rect r);
        int put(std::string win, const Point pt, char c);
        int put(std::string win, const Rect r, const CGraphicsRectConfig cfg);
        int putRoom(std::string win, const Room r, const CGraphicsRoomConfig cfg);
        int putHallway(std::string win, const Hallway h, char c);
        int putMap(std::string win, const Map& m, const CGraphicsRoomConfig cfg, char h);
        int cgetch(std::string win);

        int putHUD(std::string win, const std::shared_ptr<Player> p);

        void setLogger(const Rect r);
        int log(const char* fmt, ...);
    };
}