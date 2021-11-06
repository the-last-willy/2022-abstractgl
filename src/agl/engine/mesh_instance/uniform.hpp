#pragma once

#include "mesh_instance.hpp"

namespace agl::engine {

template<typename T>
void assign_uniform(
    MeshInstance& mi,
    std::string name,
    std::shared_ptr<T> sp)
{
    mi.uniforms[std::move(name)] = std::move(sp);
}

template<typename T>
void assign_uniform(
    MeshInstance& mi,
    std::string name,
    T&& value)
{
    auto u = std::make_shared<eng::Uniform<T>>(std::move(value));
    assign_uniform(
        mi,
        std::move(name),
        std::move(u));
}

}
