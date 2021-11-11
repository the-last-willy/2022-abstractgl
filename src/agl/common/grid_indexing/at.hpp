#pragma once

#include "grid_indexing.hpp"
#include "size.hpp"

namespace agl::common {

auto at(
    const GridIndexing&,
    std::size_t i)
{
    return i;
}

auto at(
    const GridIndexing& gi,
    std::size_t i,
    std::size_t j)
{
    return i * size(gi, 1) + j;
}

auto at(
    const GridIndexing& gi,
    std::size_t i,
    std::size_t j,
    std::size_t k)
{
    return i * size(gi, 1) * size(gi, 2) + j * size(gi, 2) + k;
}

}
