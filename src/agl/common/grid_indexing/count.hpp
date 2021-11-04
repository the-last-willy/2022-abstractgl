#pragma once

#include "dimension.hpp"
#include "grid_indexing.hpp"
#include "size.hpp"

namespace agl::common {

auto count(const GridIndexing& gi) {
    auto c = std::size_t(1);
    auto dgi = dimension(gi);
    for(decltype(dgi) i = 0; i < dgi; ++i) {
        c *= size(gi, i);
    }
    return c;
}

}
