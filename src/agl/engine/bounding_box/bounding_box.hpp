#pragma once

#include "agl/engine/transform.hpp"

#include <agl/all.hpp>

namespace agl::engine {

struct BoundingBox {
    agl::Vec3 min;
    agl::Vec3 max;

    eng::Transform transform;
};

}
