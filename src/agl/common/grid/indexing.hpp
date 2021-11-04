#pragma once

#include "grid.hpp"

namespace agl::common {

template<typename... G>
auto& indexing(const Grid<G...>& g) {
    return g.indexing();
}

}
