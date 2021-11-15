#pragma once

#include "agl/opengl/name/all.hpp"

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

template<std::size_t Extent>
void storage(Buffer b, std::span<const std::byte, Extent> s, GLbitfield flags) {
    named_buffer_storage(
        b,
        static_cast<GLsizeiptr>(size(s)),
        data(s),
        flags);
}

template<typename Type, std::size_t Extent>
void storage(Buffer b, std::span<const Type, Extent> s, GLbitfield flags = 0) {
    storage(b, std::as_bytes(s), flags);
}

template<typename Type, std::size_t Extent>
void storage(Buffer b, std::span<Type, Extent> s, GLbitfield flags = 0) {
    storage(b, std::as_bytes(s), flags);
}

template<typename Type = std::byte>
void storage(Buffer b, std::size_t s, GLbitfield flags = 0) {
    named_buffer_storage(b, sizeof(Type) * s, NULL, flags);
}

}
