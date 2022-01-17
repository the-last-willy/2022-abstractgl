#pragma once

#include "raii/query.hpp"

namespace agl::opengl {

inline
void EndQuery(GLenum target) {
    glEndQuery(target);
}

}
