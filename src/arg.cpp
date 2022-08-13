/**
 * @file arg.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "arg.h"

void DR::ArgParser::add_flag(std::string k, bool def) {
    argmap.insert({ k, Arg(Arg::FLAG, def) });
}

void DR::ArgParser::add_string(std::string k, char* def) {
    argmap.insert({ k, Arg(Arg::STRING, def) });
}

void DR::ArgParser::add_double(std::string k, double def) {
    argmap.insert({ k, Arg(Arg::DOUBLE, def) });
}

void DR::ArgParser::add_long(std::string k, long def) {
    argmap.insert({ k, Arg(Arg::LONG, def) });
}

int DR::ArgParser::parse(int argc, char** argv) {
    int i;
    char* arg = NULL;

    for (i = 1; i < argc; i++) {
        arg = *(argv + i);

        if (*arg != '-') {
            continue;
        }

        arg++;
        if (*arg == '-') {
            arg++;
        }

        auto iter = argmap.find(std::string(arg));
        if (iter == argmap.end()) {
            continue;
        }

        Arg& darg = iter->second;

        switch (darg.type) {
        case Arg::FLAG:
            darg.l = 1;
            break;
        case Arg::DOUBLE:
            if (i + 1 < argc) {
                darg.d = std::strtod(*(argv + ++i), NULL);
            }
            break;
        case Arg::LONG:
            if (i + 1 < argc) {
                darg.l = std::strtol(*(argv + ++i), NULL, 10);
            }
            break;
        case Arg::STRING:
            if (i + 1 < argc) {
                darg.s = *(argv + ++i);
            }
            break;
        }
    }

    return argc;
}