#pragma once

#include "quaternion.hpp"

#include "agl/glsl/mat/mat4.hpp"

namespace agl {

template<typename Q> constexpr
auto mat4(const Quaternion<Q>& q) {
    auto a = q.real;
    auto b = q.pure[0];
    auto c = q.pure[1];
    auto d = q.pure[2];
    
    auto aa = a * a;
    auto bb = b * b;
    auto cc = c * c;
    auto dd = d * d;
    
    auto ab = 2.f * a * b;
    auto ac = 2.f * a * c;
    auto ad = 2.f * a * d;
    auto bc = 2.f * b * c;
    auto bd = 2.f * b * d;
    auto cd = 2.f * c * d;

    return agl::mat4(
        aa + bb - cc - dd,           bc + ad,           bd - ac, 0.f,
                  bc - ad, aa - bb + cc - dd,           cd + ab, 0.f,
                  bd + ac,           cd - ab, aa - bb - cc + dd, 0.f,
                      0.f,                             0.f, 0.f, 1.f);
}

}
