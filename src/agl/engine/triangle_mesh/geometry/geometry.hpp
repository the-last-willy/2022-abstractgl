#pragma once

#include <agl/opengl/all.hpp>

#include <map>
#include <memory>

namespace agl::engine {

template<typename T = void>
struct GeometricAttribute : GeometricAttribute<void> {
    void resize(std::size_t s) override {
        values.resize(s);
    }

    const std::type_info& type() const override {
        return typeid(T);
    }

    std::vector<T> values;
};

template<>
struct GeometricAttribute<void> {
    virtual ~GeometricAttribute() = default;

    virtual void resize(std::size_t s) = 0;

    virtual const std::type_info& type() const = 0;
};

template<typename T>
GeometricAttribute<T> cast(GeometricAttribute<void>& ga) {
    if(typeid(T) == ga.type()) {
        return reinterpret_cast<GeometricAttribute<T>&>(ga);
    } else {
        throw std::logic_error("Bad cast");
    }
}

struct Geometry {
    // Faces.

    uint32_t face_count = 0;

    std::vector<uint32_t> face_material_ids;

    // Vertices.

    uint32_t vertex_count = 0;

    std::vector<agl::Vec3> vertex_colors;
    std::vector<uint32_t> vertex_material_ids;
    std::vector<agl::Vec3> vertex_normals;
    std::vector<agl::Vec3> vertex_positions;
    std::vector<agl::Vec2> vertex_texcoords;

    std::map<std::string, std::unique_ptr<GeometricAttribute<>>>
        vertex_attributes;
};

}
