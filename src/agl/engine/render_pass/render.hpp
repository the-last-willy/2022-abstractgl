#pragma once

#include "program.hpp"
#include "render_pass.hpp"

#include "agl/engine/material/all.hpp"

namespace agl::engine {

inline
void render(const RenderPass& rp) {
    bind(program(rp));
    { // Upload uniforms.
        for(auto& [name, value] : rp.uniforms) {
            auto ul = uniform_location(program(rp).program, name.c_str());
            if(ul) {
                value->set(program(rp).program, *ul);
            }
        }
    }
    { // Draw calls.
        for(auto& s : rp.subscriptions) {
            // TEMPORARY. DO SOMETHING BETTER.
            if(not s.mesh->enabled) {
                continue;
            }
            upload_to(*s.mesh, program(rp));
            for(std::size_t i = 0; i < size(s.vertex_arrays); ++i) {
                // Upload material if there is one.
                if(primitive(*s.mesh, i).material) {
                    upload_to(*primitive(*s.mesh, i).material, program(rp));
                }
                bind(s.vertex_arrays[i]);
                eng::render(primitive(*s.mesh, i), s.vertex_arrays[i]);
            }
        }
    }
    unbind(program(rp));
}

}
