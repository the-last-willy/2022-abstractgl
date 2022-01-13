#pragma once

#include "raii/all.hpp"
#include "type/optional_attribute_location.hpp"

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
