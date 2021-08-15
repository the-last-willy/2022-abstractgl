#pragma once

#include "agl/opengl/qualifier/czstring.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Optional<UniformIndex> uniform_location(
    Program p,
    czstring name)
{
    return Optional<UniformIndex>(
        glGetUniformLocation(
            p,
            name));
}

}
