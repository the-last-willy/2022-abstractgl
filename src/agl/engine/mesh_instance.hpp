#pragma once

#include "mesh.hpp"
#include "uniform.hpp"

#include <map>
#include <memory>

namespace eng {

struct MeshInstance {
    // MeshInstance(const std::shared_ptr<Mesh>& m)
    //     : mesh(m)
    // {}

    std::shared_ptr<Mesh> mesh;

    std::map<std::string, AnyUniform> uniforms;

    bool enabled = true;
};

}
