#pragma once

namespace agl::engine {

// Refer to 'https://www.khronos.org/registry/glTF/specs/2.0/glTF-2.0.html#orthographic-projection'.

struct OrthographicProjection {
    float x_mag = 1.f;
    float y_mag = 1.f;
    float z_far = 1.f;
    float z_near = -1.f;
};

inline
auto transform(const OrthographicProjection& op) {
    auto r = op.x_mag;
    auto t = op.y_mag;
    auto f = op.z_far;
    auto n = op.z_near;

    auto e22 = 2.f / (n - f);
    auto e32 = (f + n) / (n - f);

    return agl::mat4(
        1.f / r,  0.f, 0.f, 0.f,
        0.f, 1.f / t, 0.f, 0.f,
        0.f, 0.f, e22, e32,
        0.f, 0.f, 0.f, 1.f);
}

}
