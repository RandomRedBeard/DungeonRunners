/**
 * @file test_instance.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <instance.h>
#include <assert.h>

using namespace DR;

void testInstance() {
    Map m(OID::generate(), 80, 25, 3, 3);
    Instance i(std::move(m));
}

int main() {
    testInstance();
    return 0;
}