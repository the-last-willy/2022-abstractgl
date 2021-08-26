#pragma once

#include "dot.hpp"
#include "inversed.hpp"
#include "multiplication_operator.hpp"
#include "power.hpp"
#include "unary_minus_operator.hpp"

#include "quaternion.hpp"

#include <cmath>

namespace agl {

template<typename T>
auto slerp(Quaternion<T> lq, const Quaternion<T>& rq, T t) {
    auto cosine = dot(lq, rq);
    if(cosine < 0.f) {
        cosine = -cosine;
        lq = -lq;
    }
    T k0, k1;
    if(cosine < 0.9999f) {
        auto sine = std::sqrt(1.f - cosine * cosine);
        float angle = std::atan2(sine, cosine);
        k0 = std::sin((1.f - t) * angle) / sine;
        k1 = std::sin(t * angle) / sine;
    } else {
        k0 = 1.f - t;
        k1 = t;
    }
    return k0 * lq + k1 * rq;
}

}
