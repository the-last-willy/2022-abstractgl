#pragma once

#include "view_to_world_transform.hpp"
#include "world_to_camera_transform.hpp"

#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto view_to_camera_transform(const eng::Camera& c) {
    return world_to_camera_transform(c) * view_to_world_transform(c);
}

}
