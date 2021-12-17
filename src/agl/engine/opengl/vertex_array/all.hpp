#pragma once

namespace agl::engine::opengl {

// - RAII.
struct VertexArray {
    GLuint name = 0;

    VertexArray() {
        glCreateVertexArrays(1, &name);
    }

    ~VertexArray() noexcept {
        glCreateVertexArrays(1, &name);
    }
};

}
