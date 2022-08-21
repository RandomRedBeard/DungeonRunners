/**
 * @file dm.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "dm.h"

int DR::DM::joinGame(std::shared_ptr<Player> p) {
    players.insert({ p->getId(), p });
    return 0;
}

size_t DR::DM::leaveGame(OID id) {
    return players.erase(id);
}

const DR::OID DR::DM::createNewInstance() {
    auto inst = std::make_shared<Instance>(OID::generate(), Map(80, 25, 3, 3));
    instances.insert({ inst->getId(), inst });
    return inst->getId();
}

int DR::DM::joinInstance(OID pid, OID iid) {
    auto p = players.find(pid);
    if (p == players.end()) {
        return -1;
    }

    auto ins = instances.find(iid);
    if (ins == instances.end()) {
        return -1;
    }

    Point pt = ins->second->randPoint();
    p->second->setPoint(pt);
    ins->second->addPlayer(p->second, pt);
    
    return 0;
}
