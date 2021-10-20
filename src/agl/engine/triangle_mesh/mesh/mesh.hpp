#pragma once

#include "geometry/all.hpp"
#include "topology/mesh/mesh.hpp"

#include <agl/opengl/all.hpp>

namespace agl::engine {

struct TriangleMesh {
    Geometry geometry;
    Topology topology = Topology(3);
};

}
