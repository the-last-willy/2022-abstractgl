#pragma once

#include "agl/opengl/qualifier/buffer.hpp"

#include <span>

namespace agl {

// Forward declaration.
void glCreateBuffers(GLsizei n, GLuint *buffers);

inline
void create_buffers(GLsizei n, Buffer* buffers) {
    glCreateBuffers(
        n,
        reinterpret_cast<GLuint*>(buffers));
}

inline
void create(std::span<Buffer> s) {
    create_buffers(
        static_cast<GLsizei>(size(s)),
        data(s));
}

inline
Buffer buffer() {
    auto b = Buffer();
    create({&b, 1});
    return b;
}

}
