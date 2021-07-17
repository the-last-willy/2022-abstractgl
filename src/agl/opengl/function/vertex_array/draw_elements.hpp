#pragma once

#include "agl/opengl/qualifier/count.hpp"
#include "agl/opengl/qualifier/draw_mode.hpp"
#include "agl/opengl/qualifier/draw_type.hpp"
#include "agl/opengl/qualifier/offset.hpp"

#include <cstdlib>

namespace agl {

inline
void draw_elements(
    DrawMode dm,
    Count<GLsizei> c,
    DrawType dt,
    Offset<GLintptr> o)
{
    // TODO: Think some more about it.
    glDrawElements(
        static_cast<GLenum>(dm),
        static_cast<GLsizei>(c),
        static_cast<GLenum>(dt),
        reinterpret_cast<const void*>(static_cast<GLintptr>(o)));
}

}
