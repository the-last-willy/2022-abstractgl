#pragma once

#include "agl/engine/material.hpp"
#include "agl/engine/program.hpp"

namespace agl::engine {

inline
void upload_textures_to(const eng::Material& m, const eng::Program& p) {
    auto unit = 0;
    for(auto [name, texture_ptr] : m.textures) {
        auto& texture = *texture_ptr;
        auto ul = uniform_location(p.program, name.c_str());
        if(ul) {
            if(texture.sampler) {
                bind(agl::TextureUnit(unit), *texture.sampler);
            }
            bind(agl::TextureUnit(unit), texture.texture);
            agl::uniform(p.program, *ul, unit);
            unit += 1;
        }
    }
}

inline
void upload_uniforms_to(const eng::Material& m, const eng::Program& p) {
    for(auto& [name, value] : m.uniforms) {
        auto ul = uniform_location(p.program, name.c_str());
        if(ul) {
            value->set(p.program, *ul);
        }
    }
}

inline
void upload_to(const eng::Material& m, const eng::Program& p) {
    upload_textures_to(m, p);
    upload_uniforms_to(m, p);
}

}
