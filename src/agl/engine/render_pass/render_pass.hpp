#pragma once

#include "agl/engine/mesh_instance/all.hpp"
#include "agl/engine/mesh.hpp"
#include "agl/engine/primitive.hpp"
#include "agl/engine/program.hpp"
#include "agl/engine/uniform.hpp"

#include <map>
#include <memory>
#include <vector>

namespace agl::engine {

struct RenderPassSubscription {
    std::shared_ptr<const MeshInstance> mesh;

    std::vector<agl::VertexArray> vertex_arrays;
};

struct RenderPass {
    std::shared_ptr<eng::Program> program;

    std::vector<RenderPassSubscription> subscriptions;

    std::map<std::string, std::shared_ptr<eng::AnyUniform>> uniforms;
};

}
