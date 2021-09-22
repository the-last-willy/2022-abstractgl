#pragma once

#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto world_to_view_transform(const eng::Camera& c) {
    return transform(c.view);
}

}
