#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
void delete_(Sampler s) {
    glDeleteSamplers(
        1,
        &s.id);
}

}
