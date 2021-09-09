#pragma once

#include "primitive.hpp"

#include <deque>
#include <memory>

namespace eng {

struct Mesh {
    // sstd::string name = "mesh";
    std::deque<std::shared_ptr<Primitive>> primitives = {};
};

}
