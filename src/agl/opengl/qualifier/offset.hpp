#pragma once

#include "qualifier.hpp"

namespace agl {

template<typename Type>
struct Offset : Qualifier<Type> {
    using Qualifier<Type>::Qualifier;
};

template<typename R, typename P = R> constexpr
Offset<R> offset(P p) {
    return Offset<R>(static_cast<R>(p));
}

}
