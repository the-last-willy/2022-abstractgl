#pragma once

namespace agl::engine::opengl {

// - RAII.
struct Program {
    GLuint name = glCreateProgram();

    ~Program() noexcept {
        glDeleteProgram(name);
    }
};

inline
void use(const Program& p) {
    glUseProgram(p.name);
}

}
