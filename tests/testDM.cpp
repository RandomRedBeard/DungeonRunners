/**
 * @file testDM.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <assert.h>

#include <dm.h>

using namespace DR;
using namespace std;

void testMessaging() {
    srand(time(0));
    DM d;
    auto p = make_shared<Player>(OID::generate());
    p->setName("Thomas");
    d.joinGame(p);
    OID iid = d.createNewInstance();
    d.joinInstance(p->getId(), iid);
    assert(p->getPoint().x != 0);
    p->print();
}

int main() {
    testMessaging();
}