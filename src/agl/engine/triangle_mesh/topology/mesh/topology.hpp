#pragma once

#include "topology/face/topology.hpp"

#include <vector>

namespace agl::engine {

struct MeshTopology {
    uint32_t vertex_count = 0;
    std::vector<FaceTopology> faces;
};

}
