#pragma once

#include "primitive.hpp"

#include <deque>
#include <memory>

namespace eng {

struct Mesh {
    std::string name = "mesh";
    std::deque<std::shared_ptr<Primitive>> primitives = {};
};

}
