#pragma once

#include "camera/orthographic_projection.hpp"

#include "agl/engine/scene/view.hpp"

#include <agl/all.hpp>

#include <cmath>
#include <memory>
#include <optional>
#include <stdexcept>
#include <variant>

namespace eng {

struct PerspectiveProjection {
    float aspect_ratio = 1.f;
    float y_fov = agl::constant::pi / 2.f;
    std::optional<float> z_far = 1'000.f;
    float z_near = 0.1f;
};

inline
auto transform(const PerspectiveProjection& op) {
    if(op.z_far) {
        auto a = op.aspect_ratio;
        // auto y = op.y_fov;
        auto n = op.z_near;
        auto f = *op.z_far;

        // auto ty = std::tan(y / 2.f);
        auto e33 = (f + n) / (n - f);
        auto e43 = 2.f * n * f / (n - f);

        return agl::mat4(
                      1.f,       0.f, 0.f,  0.f,
                      0.f,         a, 0.f,  0.f,
                      0.f,       0.f, e33, -1.f,
                      0.f,       0.f, e43,  0.f);

        // return agl::mat4(
        //    1.f / (a * ty),       0.f, 0.f,  0.f,
        //               0.f,  1.f / ty, 0.f,  0.f,
        //               0.f,       0.f, e33, -1.f,
        //               0.f,       0.f, e43,  0.f);
    } else {
        throw std::runtime_error("Not implemented infinite perspective projection.");
    }
}

struct Camera {
    agl::engine::View view;

    std::variant<agl::engine::OrthographicProjection, PerspectiveProjection> projection
    = PerspectiveProjection();
};

// REMOVE THAT ONE.
inline
auto transform(const Camera& c) {
    if(auto op = std::get_if<agl::engine::OrthographicProjection>(&c.projection)) {
        return transform(*op) * transform(c.view);
    } else if(auto pp = std::get_if<PerspectiveProjection>(&c.projection)) {
        return transform(*pp) * transform(c.view);
    }
    throw std::runtime_error("NOT IMPLEMENTED.");
}

}
