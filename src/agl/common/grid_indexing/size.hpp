#pragma once

#include "grid_indexing.hpp"

namespace agl::common {

auto size(const GridIndexing& gi, std::size_t i) {
    return gi.size(i);
}

}
