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
    Map m(80, 25, 3, 3);
    Instance i(OID::generate(), std::move(m));
    i.generateMonsters(10);
    auto p = std::make_shared<Player>(OID::generate());
    p->setPoint(i.randPoint());
    i.addPlayer(p, p->getPoint());

    i.print();
}

void testJson() {
    Instance i(OID::generate(), Map(80, 25, 3, 3));
    i.generateMonsters(10);

    Instance t;
    t.deserialize(i.newSerialize());

    assert(t.getMonsters().size() == i.getMonsters().size());
}

int main() {
    testInstance();
    testJson();
    return 0;
}