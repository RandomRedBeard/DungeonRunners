/**
 * @file message.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "message.h"

DR::Message::Message(std::string type, Serial&& body) : type(type), body(std::move(body)) {}

DR::Serial DR::Message::serialize(Serial& o) const noexcept {
    o.put("type", type);
    o.put_child("body", body);
    return o;
}

void DR::Message::deserialize(const Serial& o) {
    type = o.get<std::string>("type");
    body = o.get_child("body");
}