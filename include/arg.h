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
        void addFlag(std::string k, bool def = true);
        void addString(std::string k, char* def = nullptr);
        void addDouble(std::string k, double def = 0);
        void addLong(std::string k, long def = 0);

        int parse(int argc, char** argv);

        bool getBool(std::string k) {
            return argmap[k].l;
        }

        std::string getString(std::string k) {
            return argmap[k].s;
        }

        double getDouble(std::string k) {
            return argmap[k].d;
        }

        long getLong(std::string k) {
            return argmap[k].l;
        }

    };
}