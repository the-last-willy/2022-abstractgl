#pragma once

#include "agl/engine/accessors.hpp"
#include "agl/engine/buffer.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

#include <map>

namespace agl::engine {

struct Database {
    std::map<std::size_t, eng::Accessor> accessors;
    std::map<std::size_t, eng::BufferView> buffer_views;
    std::map<std::size_t, eng::Buffer> buffers;
    std::map<std::size_t, eng::Material> materials;
    std::map<std::size_t, eng::Mesh> meshes;
};

}
