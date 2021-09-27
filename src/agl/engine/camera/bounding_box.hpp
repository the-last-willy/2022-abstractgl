#pragma once

#include "agl/engine/camera.hpp"
#include "view_to_camera_transform.hpp"

#include "agl/engine/bounding_box/bounding_box.hpp"

namespace agl::engine {

inline
auto bounding_box(const eng::Camera& c) {
    return BoundingBox(vec3(-1.f), vec3(1.f), view_to_camera_transform(c));
}

}
