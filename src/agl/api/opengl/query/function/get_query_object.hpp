#pragma once

#include "raii/query.hpp"

namespace agl::opengl {

inline
void GetQueryObjectui64v(
    GLuint id,
    GLenum pname,
    GLuint64* params)
{
    glGetQueryObjectui64v(
        id,
        pname,
        params);
}

inline
void GetQueryObjectui64v(
    const Query& id,
    GLenum pname,
    GLuint64* params)
{
    GetQueryObjectui64v(
        GLuint(id),
        pname,
        params);
}

inline
GLuint64 GetQueryObjectui64v(
    const Query& id,
    GLenum pname)
{
    GLuint64 param;
    GetQueryObjectui64v(
        GLuint(id),
        pname,
        &param);
    return param;
}

}
