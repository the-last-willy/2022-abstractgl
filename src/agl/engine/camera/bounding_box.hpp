#pragma once

#include "agl/engine/bounding_box/bounding_box.hpp"
#include "agl/engine/camera.hpp"

namespace agl::engine {

inline
auto bounding_box(const eng::Camera& c) {
    return BoundingBox(vec3(-1.f), vec3(1.f), transform(c));
}

}
