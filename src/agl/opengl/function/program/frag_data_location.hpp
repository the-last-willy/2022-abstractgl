#pragma once

#include "agl/opengl/qualifier/czstring.hpp"
#include "agl/opengl/qualifier/frag_data_location.hpp"
#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Optional<FragDataLocation> frag_data_location(
    Program p,
    czstring name)
{
    return glGetFragDataLocation(
        p,
        name);
}

}
