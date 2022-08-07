/**
 * @file monster.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "monster.h"

DR::Monster::Monster(std::string name) : name(name) {}

json_t* DR::Monster::to_json(json_t* o) const noexcept {
    json_object_set_new(o, "name", json_string(name.c_str()));
    pt.to_json(o);
    return o;
}

void DR::Monster::from_json(const json_t* o) {
    json_t* json_name = json_object_get(o, "name");

    if (json_name) {
        name = std::string(json_string_value(json_name));
    }

    this->pt.from_json(o);
}