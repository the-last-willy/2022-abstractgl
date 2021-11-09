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

inline
MeshInstance instance(std::shared_ptr<const eng::Mesh> m) {
    auto mi = MeshInstance();
    mi.mesh = std::move(m);
    return mi;
}

inline
MeshInstance instance(eng::Mesh&& m) {
    return instance(std::make_shared<const eng::Mesh>(std::move(m)));
}

}

