#pragma once

#include "mesh.hpp"
#include "mesh_instance.hpp"

#include <range/v3/view/indirect.hpp>

namespace agl::engine {

inline
auto primitives(const MeshInstance& mi) {
    return mesh(mi).primitives
    | ranges::views::indirect;
}

}
