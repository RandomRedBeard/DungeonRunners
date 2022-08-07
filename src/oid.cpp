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

#include <iostream>

DR::OID::OID() {
#ifdef WIN32
    UUID uuid;
    UuidCreate(&uuid);
    char* str;
    UuidToStringA(&uuid, (RPC_CSTR*)&str);
    id = str;
    RpcStringFreeA((RPC_CSTR*)&str);
#else
    // trailing zero
    char buf[36 + 1];
    uuid_t uuid;
    uuid_generate_random(uuid);
    uuid_unparse(uuid, buf);
    id = (char*)buf;
    uuid_clear(uuid);
#endif
}

json_t* DR::OID::to_json(json_t* o) const noexcept {
    json_object_set_new(o, "id", json_string(id.c_str()));
    return o;
}

void DR::OID::from_json(const json_t* o) {
    json_t* id_json = json_object_get(o, "id");
    if (id_json) {
        id = json_string_value(id_json);
    }
}


bool DR::OID::operator==(const OID& o) const noexcept {
    return id == o.id;
}

bool DR::OID::operator!=(const OID& o) const noexcept {
    return id != o.id;
}