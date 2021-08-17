#pragma once

#include "agl/opengl/name/all.hpp"
#include "agl/opengl/tag/names.hpp"

#include <span>

namespace agl {

inline
void create(std::span<Buffer> s) {
    glCreateBuffers(
        static_cast<GLsizei>(size(s)),
        reinterpret_cast<GLuint*>(data(s)));
}

inline
Buffer create(BufferTag) {
    auto b = Buffer();
    glCreateBuffers(1, &b.id);
    return b;
}

}
