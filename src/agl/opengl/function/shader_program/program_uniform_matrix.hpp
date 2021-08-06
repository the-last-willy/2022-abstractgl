#pragma once

#include "agl/glsl/mat/element_count.hpp"
#include "agl/glsl/mat/element_data.hpp"
#include "agl/glsl/mat/mat2.hpp"
#include "agl/glsl/mat/mat3.hpp"
#include "agl/glsl/mat/mat4.hpp"
#include "agl/opengl/names.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

namespace agl {

inline
void program_uniform_matrix(
    Program p,
    UniformIndex<GLint> ui,
    Mat2 m)
{
    glProgramUniformMatrix2fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

inline
void program_uniform_matrix(
    Program p,
    UniformIndex<GLint> ui,
    const Mat3& m)
{
    glProgramUniformMatrix3fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

inline
void program_uniform_matrix(
    Program p,
    UniformIndex<GLint> ui,
    const Mat4& m)
{
    glProgramUniformMatrix4fv(
        p,
        ui,
        1,
        GL_FALSE,
        element_data(m));
}

template<typename T, std::size_t CC, std::size_t RC>
void uniform(
    Program p,
    UniformIndex<GLint> ui,
    const Mat<T, CC, RC>& m)
{
    program_uniform_matrix(p, ui, m);
}

}

