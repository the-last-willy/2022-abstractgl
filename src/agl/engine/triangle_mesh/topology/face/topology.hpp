#pragma once

#include <array>

namespace agl::engine {

struct FaceTopology {
    uint32_t incident_vertex_count;
    std::array<uint32_t, 3> incident_vertices = {0, 0, 0};
};

}

