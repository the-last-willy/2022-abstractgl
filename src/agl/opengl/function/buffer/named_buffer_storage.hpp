#pragma once

#include "agl/opengl/qualifier/buffer.hpp"

#include <cstddef>
#include <span>

namespace agl {

inline
void named_buffer_storage(Buffer b, GLsizeiptr size, const std::byte* data, GLbitfield flags) {
    glNamedBufferStorage(
        static_cast<GLuint>(b),
        size,
        data,
        flags);
}

inline
void storage(Buffer b, std::span<const std::byte> s, GLbitfield flags) {
    named_buffer_storage(
        b,
        static_cast<GLsizeiptr>(size(s)),
        data(s),
        flags);
}

template<typename Type>
void storage(Buffer b, std::span<const Type> s, GLbitfield flags = 0) {
    storage(b, std::as_bytes(s), flags);
}

template<typename Type>
void storage(Buffer b, std::span<Type> s, GLbitfield flags = 0) {
    storage(b, std::as_bytes(s), flags);
}

}
