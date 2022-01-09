#pragma once

namespace agl::opengl {

// - RAII.
struct Program {
    GLuint name;

    Program() {
        name = glCreateProgram();
    }

    Program(const Program&) = delete;
    
    Program(Program&& p) {
        name = p.name;
        p.name = GL_NONE;
    }

    ~Program() noexcept {
        glDeleteProgram(name);
    }

    Program& operator=(const Program&) = delete;

    Program& operator=(Program&& p) {
        glDeleteProgram(name);
        name = p.name;
        p.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

inline
void use(const Program& p) {
    glUseProgram(p.name);
}

}
