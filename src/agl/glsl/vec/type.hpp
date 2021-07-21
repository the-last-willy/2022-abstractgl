#pragma once

#include "vec.hpp"

#include "agl/opengl/type/type.hpp"

namespace agl {

template<typename T, std::size_t N> constexpr
GLenum type(Type<Vec<T, N>>) {
    return Type<Vec<T, N>>::enum_;
}

}
