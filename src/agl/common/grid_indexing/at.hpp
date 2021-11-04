#pragma once

#include "grid_indexing.hpp"
#include "size.hpp"

namespace agl::common {

auto at(
    const GridIndexing& gi,
    std::size_t i,
    std::size_t j)
{
    return i * size(gi, 0) + j;
}

auto at(
    const GridIndexing& gi,
    std::size_t i,
    std::size_t j,
    std::size_t k)
{
    return i * size(gi, 0) * size(gi, 1) + j * size(gi, 0) + k;
}

}
