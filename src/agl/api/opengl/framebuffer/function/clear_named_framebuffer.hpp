#pragma once

#include <array>

namespace agl::opengl {

// How to handle default framebuffer (= 0) ?
inline
void ClearNamedFramebuffer(
    GLuint framebuffer,
	GLenum buffer,
	GLint drawbuffer,
	GLfloat value)
{
    glClearNamedFramebufferfv(
        framebuffer,
        buffer,
        drawbuffer,
        &value);
}

inline
void ClearNamedFramebuffer(
    GLuint framebuffer,
	GLenum buffer,
	GLint drawbuffer,
	std::array<GLfloat, 4> value)
{
    glClearNamedFramebufferfv(
        framebuffer,
        buffer,
        drawbuffer,
        data(value));
}

}
