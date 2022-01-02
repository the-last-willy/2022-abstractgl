#pragma once

namespace agl::opengl {

// - RAII.
struct Framebuffer {
    GLuint name = 0;

    Framebuffer() {
        glCreateFramebuffers(1, &name);
    }

    Framebuffer(const Framebuffer&) = delete;
    
    Framebuffer(Framebuffer&& va) {
        name = va.name;
        va.name = GL_NONE;
    }

    ~Framebuffer() noexcept {
        glDeleteFramebuffers(1, &name);
    }

    Framebuffer& operator=(const Framebuffer&) = delete;

    Framebuffer& operator=(Framebuffer&& va) {
        glDeleteFramebuffers(1, &name);
        name = va.name;
        va.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

}
