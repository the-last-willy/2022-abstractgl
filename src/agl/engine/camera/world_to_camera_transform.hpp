#pragma once

#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto world_to_camera_transform(const eng::Camera& c) {
    if(auto pp = std::get_if<eng::PerspectiveProjection>(&c.projection)) {
        return transform(*pp);
    }
    throw std::runtime_error("NOT IMPLEMENTED.");
}

}
