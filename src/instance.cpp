/**
 * @file instance.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "instance.h"

DR::Instance::Instance(DR::Map&& pmap) : pmap(std::move(pmap)) {}

void DR::Instance::generate_monsters(int n) {
}