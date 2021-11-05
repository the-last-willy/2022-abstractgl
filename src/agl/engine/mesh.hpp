#pragma once

#include "primitive.hpp"

#include <deque>
#include <memory>

namespace eng {

struct Mesh {
    std::deque<std::shared_ptr<Primitive>> primitives = {};

    // agl::Vec3 bb_min;
    // agl::Vec3 bb_max;
};

}
