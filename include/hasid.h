/**
 * @file hasid.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <oid.h>

namespace DR {
    class HasId {
    public:
        virtual const OID getId() const noexcept = 0;
    };
}