#pragma once

#include "raii/all.hpp"
#include "type/attribute_location/optional.hpp"

namespace agl::opengl {

inline
OptAttribLoc
GetAttribLocation(
    const Program& program,
    const GLchar* name)
{
    return glGetAttribLocation(
        program,
        name);
}

}
