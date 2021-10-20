#pragma once

#include "geometry/all.hpp"

#include "topology/all.hpp"

#include "agl/opengl/all.hpp"

#include <optional>
#include <vector>

namespace agl::engine {

struct TriangleMesh {
    Geometry geometry;
    Topology topology = Topology(3);
};

}
