#pragma once

#include "mesh_instance.hpp"
#include "mesh.hpp"

namespace agl::engine {

inline
auto& primitive(const MeshInstance& mi, std::size_t i) {
    return *mesh(mi).primitives[i];
}

}
