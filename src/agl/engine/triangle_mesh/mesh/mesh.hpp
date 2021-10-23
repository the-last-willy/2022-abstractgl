#pragma once

#include "geometry/all.hpp"
#include "topology/mesh/topology.hpp"

#include <agl/opengl/all.hpp>

namespace agl::engine {

struct TriangleMesh {
    Geometry geometry;
    MeshTopology topology;
};

}
