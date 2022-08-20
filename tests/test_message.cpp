/**
 * @file test_message.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <message.h>
#include <point.h>

void test_message() {
    DR::Serial o = DR::Point().Serializable::serialize();
    DR::Message m("point", std::move(o));

    m.print();
}

int main() {
    test_message();
}