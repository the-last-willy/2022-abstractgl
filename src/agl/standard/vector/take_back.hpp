#pragma once

#include <vector>

namespace agl::standard {

template<typename... V>
auto take_back(std::vector<V...>& v) {
    auto e = std::move(v.back());
    v.pop_back();
    return e;
}

template<typename... V>
auto take_back(std::vector<V...>&& v) {
    return std::move(v.back());
}

}
