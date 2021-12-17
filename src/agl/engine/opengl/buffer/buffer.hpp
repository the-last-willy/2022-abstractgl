#pragma once

namespace agl::engine::opengl {

// - RAII.
struct Buffer {
    GLuint name = 0;

    Buffer() {
        glCreateBuffers(1, &name);
    }

    ~Buffer() noexcept {
        glDeleteBuffers(1, &name);
    }
};

inline
auto size(const Buffer& b) {
    auto s = GLsizeiptr();
    glGetNamedBufferParameteri64v(b.name, GL_BUFFER_SIZE, &s);
    return s;
}

}
