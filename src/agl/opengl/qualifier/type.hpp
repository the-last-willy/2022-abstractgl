#pragma once

#include <glad/glad.h>

namespace agl {

template<typename T>
struct Type {};

constexpr
GLenum type(Type<GLfloat>) {
    return GL_FLOAT;
}

}
