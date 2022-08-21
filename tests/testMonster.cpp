/**
 * @file test_monster.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <monster.h>

using namespace std;
using namespace DR;

void testMonster() {
    srand(time(0));
    Monster mo(OID::generate(), "Ice Monster");
    mo.setLastMoved(chrono::steady_clock::now());
    mo.setSpeed(500 * (1 + rand() % 3));

    printf("%d\n", mo.getSpeed());
}

int main() {
    testMonster();
}