#pragma once

#include <vector>

namespace agl::standard {

template<typename T>
auto reserved_vector(::std::size_t n) {
    auto v = ::std::vector<T>();
    v.reserve(n);
    return v;
}

}
