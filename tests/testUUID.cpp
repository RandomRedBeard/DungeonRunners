/**
 * @file testUUID.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <hasid.h>
#include <serializable.h>

void testUuid() {
    boost::uuids::random_generator idGen;
    boost::uuids::uuid id;
    DR::Serial o;

    o.put("id", idGen());
    id = o.get<boost::uuids::uuid>("id");

    std::cout << id << std::endl;

}
int main() {
    testUuid();
    return 0;
}