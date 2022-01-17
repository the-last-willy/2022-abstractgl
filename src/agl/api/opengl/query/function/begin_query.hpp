#pragma once

#include "raii/query.hpp"

namespace agl::opengl {

inline
void BeginQuery(GLenum target, const Query& id) {
    glBeginQuery(target, id);
}

}
