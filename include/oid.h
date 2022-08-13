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

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);

        bool operator==(const OID& u) const noexcept;
        bool operator!=(const OID& u) const noexcept;
        bool operator<(const OID& u) const noexcept;

        static OID generate();
    };
}