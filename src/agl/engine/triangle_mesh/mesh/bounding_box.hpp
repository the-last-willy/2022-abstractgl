#pragma once

#include "face.hpp"
#include "mesh.hpp"
#include "topology.hpp"
#include "vertex_count.hpp"

namespace agl::engine {

inline
BoundingBox bounding_box(TriangleMesh& tm) {
    auto f0 = face(tm, 0);
    // if(not is_valid(f0)) {
    //     throw std::logic_error("Lacking implementation.");
    // }
    auto bb = bounding_box(position(incident_vertex(f0, 0)));
    for(uint32_t i = 0; i < vertex_count(tm); ++i) {
        auto&& f = face(tm, i);
        // if(is_valid(f)) {
            for(uint32_t j = 0; j < incident_vertex_count(f); ++j) {
                extend(bb.aabb, position(incident_vertex(f, j)));
            }
        // }
    }
    return bb;
}

}
