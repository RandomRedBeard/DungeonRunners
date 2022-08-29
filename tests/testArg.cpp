/**
 * @file test_arg.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>

#include <arg.h>

void testArg() {
    char* argv[] = { (char*)"bin", (char*)"-w",(char*)"10",(char*)"--flag" };
    DR::ArgParser parser;
    parser.addLong("w");
    parser.addFlag("flag");

    parser.parse(4, argv);

    assert(parser.getLong("w") == 10);
    assert(parser.getBool("flag"));

}

int main() {
    testArg();
}