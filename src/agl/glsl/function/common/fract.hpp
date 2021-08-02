#pragma once

#include "floor.hpp"

namespace agl {

template<typename Type> constexpr
Type fract(Type t) {
    return t - floor(t);
}

}
