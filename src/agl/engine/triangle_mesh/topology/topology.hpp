#pragma once

#include <vector>

namespace agl::engine {

struct Topology {
    explicit
    Topology(uint32_t vertex_per_face)
        : vertex_per_face(vertex_per_face)
    {}

    uint32_t face_count = 0;
    uint32_t vertex_count = 0;

    uint32_t vertex_per_face;

    std::vector<uint32_t> face_indices;
};

}
