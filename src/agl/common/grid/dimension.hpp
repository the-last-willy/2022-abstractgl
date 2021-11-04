#pragma once

#include "grid_indexing/dimension.hpp"
#include "grid.hpp"
#include "indexing.hpp"

namespace agl::common {

template<typename... G>
auto dimension(const Grid<G...>& g) {
    return dimension(indexing(g));
}

}
