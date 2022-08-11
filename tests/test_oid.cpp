/**
 * @file test_uuid.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <map>
#include <assert.h>

#include <oid.h>

void test_oid() {
    DR::OID o = DR::OID::generate();
    o.print();

    DR::OID oid;

    std::map<DR::OID, int> m;
    m.insert({o, 1});
    assert(m[o] == 1);
}

int main() {
    test_oid();
}