#pragma once

#include <algorithm>

namespace agl::standard {

template<typename ForwardIt, typename... Args> constexpr
auto max_element_distance(ForwardIt first, Args&&... as) {
    return std::distance(
        first,
        std::max_element(
            first,
            std::forward<Args>(as)...));
}

}
