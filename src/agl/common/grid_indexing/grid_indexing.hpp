#pragma once

#include <ranges>
#include <vector>

namespace agl::common {

class GridIndexing {
    std::vector<std::size_t> size_;

public:
    GridIndexing() = default;

    template<typename It> explicit
    GridIndexing(It first, It last)
        : size_(first, last)
    {}

    auto dimension() const {
        return std::size(size_);
    }

    auto size(std::size_t i) const {
        return size_[i];
    }
};

inline
auto grid_indexing(std::initializer_list<std::size_t> il) {
    return GridIndexing(begin(il), end(il));
}

inline
auto grid_indexing(const std::ranges::range auto& r) {
    return GridIndexing(begin(r), end(r));
}

inline
auto grid_indexing(std::size_t i) {
    return grid_indexing({i});
}

inline
auto grid_indexing(std::size_t i, std::size_t j) {
    return grid_indexing({i, j});
}


}
