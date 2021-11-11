#pragma once

#include "dimension.hpp"
#include "grid_indexing.hpp"
#include "size.hpp"

namespace agl::common {

auto size_or(const GridIndexing& gi, std::size_t i, std::size_t alternative) {
    if(i < dimension(gi)) {
        return size(gi, i);
    } else {
        return alternative;
    }
}

}
