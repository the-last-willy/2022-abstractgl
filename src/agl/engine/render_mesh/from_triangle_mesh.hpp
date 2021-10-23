#pragma once

#include "agl/engine/accessor/all.hpp"
#include "agl/engine/triangle_mesh/all.hpp"
#include "agl/engine/material.hpp"
#include "agl/engine/mesh.hpp"

#include "agl/geometry/all.hpp"

namespace agl::engine {

// BIG MEMORY LEAK AROUND HERE
inline
auto triangle_mesh(const agl::engine::TriangleMesh& tm, const std::vector<std::shared_ptr<eng::Material>>& materials) {
    auto m = eng::Mesh();
    auto indices = std::vector<uint32_t>();
    auto positions = std::make_shared<eng::Accessor>(
        accessor(std::span(geometry(tm).vertex_positions)));
    for(uint32_t f = 0; f < face_count(tm);) {
        auto& p = *m.primitives.emplace_back(std::make_shared<eng::Primitive>());
        {
            p.attributes["v"] = positions;
            p.draw_mode = agl::DrawMode::triangles;
            p.draw_type = agl::DrawType::unsigned_int;
        }

        auto material_group = material_id(incident_vertex(face(tm, f), 0));
        if(not empty(materials)) {
            p.material = materials[material_group];
        }

        for(; f < face_count(tm); ++f) {
            auto&& fa = face(tm, f);
            for(uint32_t v = 0; v < incident_vertex_count(fa); ++v) {
                auto&& iv = incident_vertex(fa, v);
                if(material_group != material_id(iv)) {
                    goto label;
                }
                indices.push_back(index(iv));
            }
        }

        label:

        // std::cout << "Primitive " << material_group << ": ";
        // for(auto&& i : indices) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;

        p.indices = std::make_shared<eng::Accessor>(accessor(std::span(indices)));
        p.primitive_count = agl::Count<GLsizei>(
            static_cast<GLsizei>(size(indices)));
        indices.clear();
    }
    return m;
}

}
