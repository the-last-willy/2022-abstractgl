#pragma once

#include "camera.hpp"

namespace agl::engine {

inline
auto normal_transform(const eng::Camera& c) {
    return transpose(inverse(transform(c.view)));
}

}

