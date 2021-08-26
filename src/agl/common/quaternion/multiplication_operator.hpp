#pragma once

#include "quaternion.hpp"

#include "agl/glsl/function/geometric/cross.hpp"
#include "agl/glsl/function/geometric/dot.hpp"
#include "agl/glsl/function/vector/addition.hpp"
#include "agl/glsl/function/vector/multiplication.hpp"

namespace agl {

template<typename T> constexpr
auto operator*(const Quaternion<T>& lq, const Quaternion<T>& rq) {
    auto real = lq.real * rq.real - dot(lq.pure, rq.pure);
    auto pure = lq.real * rq.pure + rq.real * lq.pure + cross(lq.pure, rq.pure);
    return Quaternion(std::move(real), std::move(pure));
}

template<typename T> constexpr
auto operator*(const T& lt, const Quaternion<T>& rq) {
    return Quaternion(lt * rq.real, lt * rq.pure);
}

template<typename T> constexpr
auto operator*(const Quaternion<T>& lq, const T& rt) {
    return Quaternion(lq.real * rt, lq.pure * rt);
}

}
