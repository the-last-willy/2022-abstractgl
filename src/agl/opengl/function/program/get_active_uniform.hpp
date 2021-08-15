#pragma once

#include "agl/opengl/function/program/get_program.hpp"
#include "agl/opengl/name/all.hpp"
#include "agl/opengl/qualifier/uniform_index.hpp"

#include <string>

namespace agl {

inline
void get_active_uniform(
    Program p,
  	UniformIndex ui,
  	GLsizei bufSize,
  	GLsizei *length,
  	GLint *size,
  	GLenum *type,
  	GLchar *name)
{
	glGetActiveUniform(
        p,
        ui,
        bufSize,
        length,
        size,
        type,
        name);
}

struct UniformInformation {
    std::string name;
    GLint size;
    GLenum type;
};

inline 
UniformInformation active_uniform(
    Program p,
  	UniformIndex ui)
{
    auto i = UniformInformation();
    i.name.resize(active_uniform_max_length(p));
    auto length = GLsizei(0);
    get_active_uniform(
        p,
        ui,
        static_cast<GLsizei>(std::size(i.name)),
        &length,
        &i.size,
        &i.type,
        data(i.name));
    i.name.resize(length);
    return i;
}

}
