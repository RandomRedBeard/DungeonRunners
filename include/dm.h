/**
 * @file dm.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <map>

#include <message.h>
#include <player.h>
#include <instance.h>

namespace DR {
    class DM {
    public:
        // Messaging

        std::map<OID, std::shared_ptr<Instance>> instances;
        std::map<OID, std::shared_ptr<Player>> players;

        // Action methods
        int joinGame(std::shared_ptr<Player> p);
        size_t leaveGame(OID id);

        const OID createNewInstance();
        int joinInstance(OID pid, OID iid);
    };
}