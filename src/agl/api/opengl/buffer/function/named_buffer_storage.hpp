#pragma once

#include "buffer.hpp"

#include <initializer_list>
#include <span>

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

// Might be better to use a concept encapsulating both init_list and span.
// Only data, size and value_type are required.

// 'std::initializer_list'.

template<typename T>
void NamedBufferStorage(
    const Buffer& b,
    std::initializer_list<T> il,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size(il) * sizeof(T),
        data(il),
        flags);
}

// 'std::span'.

template<typename T>
void NamedBufferStorage(
    const Buffer& b,
    std::span<T> s,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size(s) * sizeof(T),
        data(s),
        flags);
}

}
