#pragma once

#include "raii/all.hpp"

namespace agl::opengl {

inline
BufferMapping MapNamedBuffer(
    const Buffer& b,
    GLbitfield access)
{
    return BufferMapping(b, glMapNamedBuffer(b, access));
}

}
