#pragma once

#include "buffer.hpp"

#include <concepts>

namespace agl::opengl {

////////////////////////////////////////////////////////////////////////////////
// Standard library compatibility.

// Standard containers: array, span, vector, ...
template<typename Container> requires
requires(Container c) {
    Container::value_type;
    { data(c) } -> std::convertible_to<const Container::value_type*>;
    { size(c) } -> std::integral;
}
void GetNamedBufferSubData(
    const Buffer& b,
    GLintptr offset,
    Container& c)
{
    glGetNamedBufferSubData(
        b,
        offset,
        GLsizei(size(c)) * sizeof(Container::value_type),
        data(c));
}

}
