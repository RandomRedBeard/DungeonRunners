/**
 * @file testServer.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <boost/asio.hpp>
#include <boost/function.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>

#include <assert.h>

#include <message.h>
#include <arg.h>
#include <mapPathfinder.h>
#include <instance.h>
#include <map.h>
#include <pathfinder.h>
#include <cGraphics.h>
#include <player.h>
#include <monster.h>
#include <session.h>

using namespace DR;
using namespace std;

void myprint(const char* buf) {
    cout << buf << endl;
}


int main() {
    // auto a = 
    // auto a1 = std::bind(&myprint, "hello");

    std::function<void (void)> func = std::bind(&myprint, "Hello");
    func();

    // a();
    // a1();
    return 0;
}