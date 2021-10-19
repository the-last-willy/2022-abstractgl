#pragma once

#include "camera.hpp"

namespace agl::engine {

inline
auto eye_to_world(const eng::Camera& c) {
    return transform(c.view);
}

}
