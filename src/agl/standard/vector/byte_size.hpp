#pragma once

#include <vector>

namespace agl::standard {

template<typename... V>
std::size_t byte_size(const std::vector<V...>& v) {
    return sizeof(std::vector<V...>::value_type) * size(v);
}

}
