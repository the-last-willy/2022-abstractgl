#pragma once

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

auto grid_indexing(std::initializer_list<std::size_t> il) {
    return GridIndexing(begin(il), end(il));
}

}
