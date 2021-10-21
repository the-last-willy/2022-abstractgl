#pragma once

#include "mesh.hpp"
#include "transform.hpp"

#include "agl/engine/camera/camera.hpp"
#include "agl/engine/mesh_instance/mesh_instance.hpp"

#include <agl/opengl/all.hpp>

#include <memory>
#include <optional>
#include <vector>

namespace eng {

struct Skin;

struct Node {
    std::vector<std::shared_ptr<Node>> children = {};

    Transform transform = {};
    
    std::optional<std::shared_ptr<Camera>> camera = std::nullopt;
    // SHOULD BE REMOVED.
    std::optional<std::shared_ptr<Mesh>> mesh = std::nullopt;
    std::optional<std::shared_ptr<Skin>> skin = std::nullopt;

    std::shared_ptr<agl::engine::MeshInstance> mesh_instance;
};

template<typename F>
void traverse(Node& n, F f, agl::Mat4 parent_transform = mat4(agl::identity)) {
    auto transform = parent_transform * mat4(n.transform);
    if(n.mesh) {
        f(**n.mesh, transform);
    }
    for(auto& c : n.children) {
        traverse(*c, f, transform);
    }
}

template<typename F>
void traverse_cameras(Node& n, F f, agl::Mat4 parent_transform = mat4(agl::identity)) {
    auto transform = parent_transform * mat4(n.transform);
    if(n.camera) {
        f(**n.camera, transform);
    }
    for(auto& c : n.children) {
        traverse_cameras(*c, f, transform);
    }
}

}
