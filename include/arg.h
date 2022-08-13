/**
 * @file arg.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <map>
#include <vector>
#include <string>

namespace DR {
    struct Arg {
        enum Type {
            FLAG, STRING, DOUBLE, LONG
        };

        Type type;

        long l;
        double d;
        char* s;

        Arg() {}
        Arg(Type type, bool l) : type(type), l(l) {}
        Arg(Type type, char* s) : type(type), s(s) {}
        Arg(Type type, double d) : type(type), d(d) {}
        Arg(Type type, long l) : type(type), l(l) {}

        virtual ~Arg() {}
    };
    class ArgParser {
        std::map<std::string, Arg> argmap;
    public:
        void add_flag(std::string k, bool def = true);
        void add_string(std::string k, char* def = nullptr);
        void add_double(std::string k, double def = 0);
        void add_long(std::string k, long def = 0);

        int parse(int argc, char** argv);

        bool get_bool(std::string k) {
            return argmap[k].l;
        }

        std::string get_string(std::string k) {
            return argmap[k].s;
        }

        double get_double(std::string k) {
            return argmap[k].d;
        }

        long get_long(std::string k) {
            return argmap[k].l;
        }

    };
}