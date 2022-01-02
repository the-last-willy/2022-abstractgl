#pragma once

#include "buffer.hpp"

#include <span>

namespace agl::opengl {

template<typename T>
void NamedBufferStorage(
    const Buffer& b,
    std::span<const T> s,
    GLenum flags = GL_NONE)
{
    glNamedBufferStorage(
        b,
        size(s) * sizeof(T),
        data(s),
        flags);
}

template<typename T>
void NamedBufferStorage(
    const Buffer& b,
    std::span<T> s,
    GLenum flags = GL_NONE)
{
    NamedBufferStorage(b, std::span<const T>(s), flags);
}

}
