/**
 * @file rect.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <serializable.h>
#include <point.h>

namespace DR {
    class Rect : public Serializable {
    public:
        int x, y, w, h;
        Rect(int x, int y, int w, int h);
        Rect();

        bool contains(const Point pt) const noexcept;
        unsigned int area() const noexcept;

        json_t* to_json(json_t* o) const noexcept;
        void from_json(const json_t* o);

        bool operator==(const Rect& r) const noexcept;
        bool operator!=(const Rect& r) const noexcept;

    };
} // namespace DR 