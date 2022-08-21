/**
 * @file uuid.h
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
#include <windows.h>
#else
#include <uuid/uuid.h>
#endif

#include <string>

#include <serializable.h>

namespace DR {
    class OID : public Serializable {
        std::string id;
    public:
        const std::string get() const noexcept { return id; }

        Serial serialize(Serial& o) const noexcept;
        void deserialize(const Serial& o);

        bool operator==(const OID& u) const noexcept;
        bool operator!=(const OID& u) const noexcept;
        bool operator<(const OID& u) const noexcept;

        static OID generate();
    };
}