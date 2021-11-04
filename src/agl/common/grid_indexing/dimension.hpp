#pragma once

#include "grid_indexing.hpp"

namespace agl::common {

auto dimension(const GridIndexing& gi) {
    return gi.dimension();
}

}
