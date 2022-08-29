/**
 * @file message.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <serializable.h>

namespace DR {
    class Message : public Serializable {
        std::string type;
        Serial body;
    public:
        Message(const Serial& se);
        Message(std::string type, Serial&& body);

        std::string getType() const noexcept { return type; }
        const Serial& getBody() const noexcept { return body; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);
    };
}