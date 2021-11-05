#pragma once

#include "agl/engine/transform.hpp"

#include <agl/common/all.hpp>
#include <agl/opengl/all.hpp>

namespace agl::engine {

struct BoundingBox {
    // Axis aligned bounding box.
    common::Interval<3> aabb;

    eng::Transform transform;
};

}
