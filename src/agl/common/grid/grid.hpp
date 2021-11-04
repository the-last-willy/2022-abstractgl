#pragma once

#include "grid_indexing/count.hpp"
#include "grid_indexing/grid_indexing.hpp"

#include <vector>

namespace agl::common {

template<typename T>
class Grid {
    GridIndexing indexing_;
    std::vector<T> elements;

public:
    Grid() = default;

    Grid(const GridIndexing& gi)
        : indexing_(gi)
    {
        elements.resize(count(indexing_));
    }

    Grid(GridIndexing&& gi)
        : indexing_(std::move(gi))
    {
        elements.resize(count(indexing_));
    }

    const T& at(std::size_t i) const {
        return elements[i];
    }

    T& at(std::size_t i) {
        return elements[i];
    }

    auto& indexing() const noexcept {
        return indexing_;
    }
};

}
