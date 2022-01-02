#pragma once

namespace agl::opengl {

// - RAII.
struct Buffer {
    GLuint name;

    Buffer() {
        glCreateBuffers(1, &name);
    }

    Buffer(const Buffer&) = delete;

    Buffer(Buffer&& b) {
        name = b.name;
        b.name = GL_NONE;
    }

    ~Buffer() noexcept {
        glDeleteBuffers(1, &name);
    }

    Buffer& operator=(const Buffer&) = delete;

    Buffer& operator=(Buffer&& b) {
        glDeleteBuffers(1, &name);
        name = b.name;
        b.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

}
