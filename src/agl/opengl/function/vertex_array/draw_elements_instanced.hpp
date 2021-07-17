#pragma once

#include "agl/opengl/qualifier/count.hpp"
#include "agl/opengl/qualifier/draw_mode.hpp"
#include "agl/opengl/qualifier/draw_type.hpp"
#include "agl/opengl/qualifier/instance_count.hpp"
#include "agl/opengl/qualifier/offset.hpp"

#include <cstdlib>

namespace agl {

inline
void draw_elements_instanced(
    DrawMode dm,
    Count<GLsizei> c,
    DrawType dt,
    Offset<GLintptr> o,
    InstanceCount<GLsizei> ic)
{
    glDrawElementsInstanced(
        static_cast<GLenum>(dm),
        static_cast<GLsizei>(c),
        static_cast<GLenum>(dt),
        reinterpret_cast<const void*>(static_cast<GLintptr>(o)),
        static_cast<GLsizei>(ic));
}

inline
void draw_elements(
    DrawMode dm,
    Count<GLsizei> c,
    DrawType dt,
    Offset<GLintptr> o,
    InstanceCount<GLsizei> ic)
{
    draw_elements_instanced(dm, c, dt, o, ic);
}

}
