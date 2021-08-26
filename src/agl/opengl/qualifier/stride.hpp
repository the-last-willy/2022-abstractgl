#pragma once

#include "qualifier.hpp"

namespace agl {

template<typename Type>
struct Stride : Qualifier<Type> {
    using Qualifier<Type>::Qualifier;
};

template<typename R, typename P = R> constexpr
Stride<R> stride(P p) {
    return Stride<R>(static_cast<R>(p));
}


}
