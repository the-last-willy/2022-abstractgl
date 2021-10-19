#pragma once

#include "camera.hpp"
#include "world_to_clip.hpp"

#include "agl/engine/bounding_box/bounding_box.hpp"

namespace agl::engine {

inline
auto bounding_box(const eng::Camera& c) {
    return BoundingBox(vec3(-1.f), vec3(1.f), world_to_clip(c));
}

}
