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

void test_arg() {
    char* argv[] = { (char*)"bin", (char*)"-w",(char*)"10",(char*)"--flag" };
    DR::ArgParser parser;
    parser.add_long("w");
    parser.add_flag("flag");

    parser.parse(4, argv);

    assert(parser.get_long("w") == 10);
    assert(parser.get_bool("flag"));

}

int main() {
    test_arg();
}