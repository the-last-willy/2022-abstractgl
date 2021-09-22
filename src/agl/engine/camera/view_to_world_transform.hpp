#pragma once

#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto view_to_world_transform(const eng::Camera& c) {
    return inverse(transform(c.view));
}

}
