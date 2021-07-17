#pragma once

#include "agl/glsl/vec/data.hpp"
#include "agl/glsl/vec/size.hpp"
#include "agl/glsl/vec/vec2.hpp"
#include "agl/glsl/vec/vec3.hpp"
#include "agl/glsl/vec/vec4.hpp"
#include "agl/opengl/qualifier/program.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void program_uniform(
    Program p,
    UniformIndex<GLint> ui,
    Vec2 v)
{
    glProgramUniform2fv(
        p,
        ui,
        static_cast<GLsizei>(size(v)),
        data(v));
}

inline
void program_uniform(
    Program p,
    UniformIndex<GLint> ui,
    Vec3 v)
{
    glProgramUniform3fv(
        p,
        ui,
        static_cast<GLsizei>(size(v)),
        data(v));
}

inline
void program_uniform(
    Program p,
    UniformIndex<GLint> ui,
    Vec4 v)
{
    glProgramUniform4fv(
        p,
        ui,
        static_cast<GLsizei>(size(v)),
        data(v));
}

template<typename T, std::size_t N>
void uniform(
    Program p,
    UniformIndex<GLint> ui,
    Vec<T, N> v)
{
    program_uniform(p, ui, v);
}

}

