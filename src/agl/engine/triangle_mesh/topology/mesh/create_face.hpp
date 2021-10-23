#pragma once

#include "proxy/vertex/proxy.hpp"
#include "face_count.hpp"
#include "topology.hpp"

#include <span>

namespace agl::engine {

inline
uint32_t create_face(MeshTopology& t, uint32_t vertex_count) {
    auto&& f = t.faces.emplace_back();
    f.incident_vertex_count = vertex_count;
    return static_cast<uint32_t>(size(t.faces) - 1);
}

}
