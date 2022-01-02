#pragma once

#include "buffer.hpp"

namespace agl::opengl {

// The return type if obviously inadequate.
// Might be multiple values ?
// A boolean could be a better fit ?
inline
GLint GetNamedBufferParameter(
    const Buffer& b,
    GLenum pname)
{
    GLint params;
    glGetNamedBufferParameteriv(b, pname, &params);
    return params;
}

}
