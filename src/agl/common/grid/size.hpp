#pragma once

#include "grid_indexing/size.hpp"
#include "grid.hpp"
#include "indexing.hpp"

namespace agl::common {

template<typename... G>
auto size(const Grid<G...>& g, std::size_t i) {
    return size(indexing(g), i);
}

}
