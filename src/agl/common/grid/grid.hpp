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

    auto begin() const {
        return std::begin(elements);
    }

    auto begin() {
        return std::begin(elements);
    }

    auto end() const {
        return std::end(elements);
    }

    auto end() {
        return std::end(elements);
    }

    auto& indexing() const noexcept {
        return indexing_;
    }
};

template<typename T>
auto grid(std::size_t s0) {
    return Grid<T>(grid_indexing(s0));
}

template<typename T>
auto grid(std::size_t s0, std::size_t s1) {
    return Grid<T>(grid_indexing(s0, s1));
}

template<typename T>
auto grid(std::size_t s0, std::size_t s1, std::size_t s2) {
    return Grid<T>(grid_indexing(s0, s1, s2));
}

}
