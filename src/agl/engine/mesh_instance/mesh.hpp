#pragma once

#include "mesh_instance.hpp"

namespace agl::engine {

inline
auto& mesh(const MeshInstance& mi) {
    return *mi.mesh;
}

}
