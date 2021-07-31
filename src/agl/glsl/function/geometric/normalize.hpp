#pragma once

#include "length.hpp"

#include "agl/glsl/vec/vec.hpp"

namespace agl {

template<std::size_t N>
Vec<float, N> normalize(Vec<float, N> v) {
    return v / length(v);
}

}
