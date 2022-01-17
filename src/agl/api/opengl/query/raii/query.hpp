#pragma once

namespace agl::opengl {

/**
 * Asynchronous query.
 * 
 * Invariants:
 * - RAII.
 */
struct Query {
    GLuint name = 0;

    Query(GLenum target) {
        glCreateQueries(target, 1, &name);
    }

    Query(const Query&) = delete;
    
    Query(Query&& s) {
        name = s.name;
        s.name = GL_NONE;
    }

    ~Query() noexcept {
        glDeleteQueries(1, &name);
    }

    Query& operator=(const Query&) = delete;

    Query& operator=(Query&& s) {
        glDeleteQueries(1, &name);
        name = s.name;
        s.name = GL_NONE;
        return *this;
    }

    operator GLuint() const noexcept {
        return name;
    }
};

}
