#pragma once

#include "raii/all.hpp"

namespace agl::engine::opengl {

inline
BufferMapping MapNamedBuffer(
    const Buffer& b,
    GLbitfield access)
{
    return BufferMapping(&b, glMapNamedBuffer(b, access));
}

}
