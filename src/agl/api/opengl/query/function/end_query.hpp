#pragma once

#include "raii/query.hpp"

namespace agl::opengl {

inline
void EndQuery(const Query& id) {
    glEndQuery(id);
}

}
