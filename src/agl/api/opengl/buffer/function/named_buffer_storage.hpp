#pragma once

#include "buffer.hpp"

#include <concepts>
#include <initializer_list>

namespace agl::opengl {

inline
void NamedBufferStorage(
    const Buffer& b,
    GLsizei size,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size,
        NULL,
        flags);
}

////////////////////////////////////////////////////////////////////////////////
// Standard library compatibility.

// Standard containers: array, span, vector, ...
template<typename Container> requires
requires(Container c) {
    Container::value_type;
    { data(c) } -> std::convertible_to<const Container::value_type*>;
    { size(c) } -> std::integral;
}
void NamedBufferStorage(
    const Buffer& b,
    const Container& c,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size(c) * sizeof(Container::value_type),
        data(c),
        flags);
}

template<typename T>
void NamedBufferStorage(
    const Buffer& b,
    const std::initializer_list<T>& il,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size(il) * sizeof(T),
        data(il),
        flags);
}

}
