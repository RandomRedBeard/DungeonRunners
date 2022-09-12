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
    boost::uuids::random_generator idGen;
    Map m(80, 25, 3, 3);
    Instance i(idGen(), std::move(m));
    auto p = std::make_shared<Player>(idGen());
    p->setPoint(i.randPoint());
    i.addPlayer(p, p->getPoint());

    i.print();
}

void testJson() {
    boost::uuids::random_generator idGen;
    Instance i(idGen(), Map(80, 25, 3, 3));

    Instance t;
    t.deserialize(i.newSerialize());
}

int main() {
    testInstance();
    testJson();
    return 0;
}