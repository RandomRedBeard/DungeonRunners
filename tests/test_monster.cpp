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

void test_monster() {
    srand(time(0));
    Monster mo("Ice Monster");
    mo.set_last_moved(chrono::steady_clock::now());
    mo.set_speed(500 * (1 + rand() % 3));

    printf("%d\n", mo.get_speed());
}

int main() {
    test_monster();
}