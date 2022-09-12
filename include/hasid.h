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

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace DR {
    class HasId {
    public:
        virtual const boost::uuids::uuid getId() const noexcept = 0;
    };
}