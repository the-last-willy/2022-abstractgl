#pragma once

#include "quaternion.hpp"

#include "agl/glsl/function/geometric/cross.hpp"
#include "agl/glsl/function/geometric/dot.hpp"
#include "agl/glsl/function/vector/addition.hpp"
#include "agl/glsl/function/vector/multiplication.hpp"

namespace agl {

template<typename T> constexpr
auto operator+(const Quaternion<T>& lq, const Quaternion<T>& rq) {
    return Quaternion<T>(lq.real + rq.real, lq.pure + rq.pure);
}


}
