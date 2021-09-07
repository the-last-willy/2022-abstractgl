#pragma once

#include "mesh.hpp"
#include "uniform.hpp"

#include <map>
#include <memory>

namespace eng {

struct MeshInstance {
    std::shared_ptr<Mesh> mesh;

    std::map<std::string, AnyUniform> uniforms;
};

}
