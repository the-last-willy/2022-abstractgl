#pragma once

#include "get_program.hpp"

#include "agl/opengl/qualifier/attribute_index.hpp"
#include "agl/opengl/name/all.hpp"

#include <string>

namespace agl {

inline
void get_active_attrib(
    Program p,
  	AttributeIndex<GLuint> ai,
  	GLsizei bufSize,
  	GLsizei *length,
  	GLint *size,
  	GLenum *type,
  	GLchar *name)
{
    glGetActiveAttrib(
        p,
        ai,
        bufSize,
        length,
        size,
        type,
        name);
}

struct AttributeInformation {
    std::string name;
    GLint size;
    GLenum type;
};

inline 
AttributeInformation active_attrib(
    Program p,
  	AttributeIndex<GLuint> ai)
{
    auto i = AttributeInformation();
    i.name.resize(active_attribute_max_length(p));
    auto length = GLsizei(0);
    get_active_attrib(
        p,
        ai,
        static_cast<GLsizei>(std::size(i.name)),
        &length,
        &i.size,
        &i.type,
        data(i.name));
    i.name.resize(length);
    return i;
}

}
