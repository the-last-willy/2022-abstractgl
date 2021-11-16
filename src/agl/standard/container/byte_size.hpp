#pragma once

#include <vector>

namespace agl::standard {

inline
std::size_t byte_size(const auto& c) {
    return sizeof(typename decltype(c)::value_type) * size(c);
}

}
