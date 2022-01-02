#pragma once

namespace agl::opengl {

// - RAII.
struct Sampler {
    GLuint name = 0;

    Sampler() {
        glCreateSamplers(1, &name);
    }

    Sampler(const Sampler&) = delete;
    
    Sampler(Sampler&& s) {
        name = s.name;
        s.name = GL_NONE;
    }

    ~Sampler() noexcept {
        glDeleteSamplers(1, &name);
    }

    Sampler& operator=(const Sampler&) = delete;

    Sampler& operator=(Sampler&& s) {
        glDeleteSamplers(1, &name);
        name = s.name;
        s.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

}
