/**
 * @file uuid.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "oid.h"

DR::OID DR::OID::generate() {
    OID id;
#ifdef WIN32
    UUID uuid;
    UuidCreate(&uuid);
    char* str;
    UuidToStringA(&uuid, (RPC_CSTR*)&str);
    id.id = str;
    RpcStringFreeA((RPC_CSTR*)&str);
#else
    // trailing zero
    char buf[36 + 1];
    uuid_t uuid;
    uuid_generate_random(uuid);
    uuid_unparse(uuid, buf);
    id.id = (char*)buf;
    uuid_clear(uuid);
#endif
    return id;
}

DR::Serial DR::OID::serialize(Serial o) const noexcept {
    o.put("id", id);
    return o;
}

void DR::OID::deserialize(const Serial o) {
    id = o.get<std::string>("id");
}


bool DR::OID::operator==(const OID& o) const noexcept {
    return id == o.id;
}

bool DR::OID::operator!=(const OID& o) const noexcept {
    return id != o.id;
}

bool DR::OID::operator<(const OID& o) const noexcept {
    return id < o.id;
}