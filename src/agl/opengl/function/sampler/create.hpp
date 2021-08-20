#pragma once

#include "agl/opengl/name/all.hpp"

namespace agl {

inline
Sampler create(SamplerTag) {
    auto s = Sampler();
    glCreateSamplers(
        1,
        &s.id);
    return s;
}

}
