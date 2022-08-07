/**
 * @file oid.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#ifdef WIN32
#else
#include <uuid/uuid.h>
#endif

#include <string>

#include <serializable.h>

namespace DR {
    class OID : public Serializable {
        std::string id;
    public:
        OID();

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);

        bool operator==(const OID& o) const noexcept;
        bool operator!=(const OID& o) const noexcept;
    };
}