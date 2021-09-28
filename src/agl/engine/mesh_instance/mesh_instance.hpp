#pragma once

#include "agl/engine/mesh.hpp"
#include "agl/engine/uniform.hpp"

#include <memory>

namespace agl::engine {

struct MeshInstance {
    std::shared_ptr<const eng::Mesh> mesh;

    std::map<std::string, std::shared_ptr<eng::AnyUniform>> uniforms;

    bool enabled = true;
};

}

