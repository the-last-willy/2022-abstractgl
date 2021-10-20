#pragma once

#include "proxy/vertex/proxy.hpp"
#include "face_count.hpp"
#include "mesh.hpp"

#include <span>

namespace agl::engine {

inline
uint32_t create_face(Topology& t, uint32_t vertex_count) {
    t.faces.emplace_back(vertex_count);
    return static_cast<uint32_t>(size(t.faces) - 1);
}

}
