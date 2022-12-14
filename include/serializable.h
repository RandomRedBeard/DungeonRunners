/**
 * @file serializable.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace DR {

    typedef boost::property_tree::ptree Serial;

    /**
     * @brief Parent struct for json serialization
     * 
     */
    struct Serializable {
        virtual Serial serialize(Serial& o) const noexcept = 0;
        inline Serial newSerialize() const noexcept {
            Serial o;
            return serialize(o);
        }
        virtual void deserialize(const Serial& o) = 0;

        void print() const noexcept {
            auto o = newSerialize();
            boost::property_tree::write_json(std::cout, o);
        }

    };
} // namespace DR
