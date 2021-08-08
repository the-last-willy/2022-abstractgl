#pragma once

#include "agl/glsl/vec/data.hpp"
#include "agl/glsl/vec/size.hpp"
#include "agl/glsl/vec/vec2.hpp"
#include "agl/glsl/vec/vec3.hpp"
#include "agl/glsl/vec/vec4.hpp"
#include "agl/opengl/names.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void uniform(
    Program p,
    UniformIndex ui,
    Vec2 v)
{
    glProgramUniform2fv(
        p,
        ui,
        1,
        data(v));
}

inline
void uniform(
    Program p,
    UniformIndex ui,
    Vec3 v)
{
    glProgramUniform3fv(
        p,
        ui,
        1,
        data(v));
}

inline
void uniform(
    Program p,
    UniformIndex ui,
    Vec4 v)
{
    glProgramUniform4fv(
        p,
        ui,
        1,
        data(v));
}

}

