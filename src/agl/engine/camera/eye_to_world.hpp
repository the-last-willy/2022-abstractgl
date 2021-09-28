#pragma once

#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto eye_to_world(const eng::Camera& c) {
    return transform(c.view);
}

}
