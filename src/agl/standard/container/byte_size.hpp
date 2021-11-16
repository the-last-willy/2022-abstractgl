#pragma once

#include <vector>

namespace agl::standard {

template<typename Container>
requires requires (Container c) {
    typename Container::value_type;
    size(c);
}
auto byte_size(const Container& c) {
    return sizeof(typename Container::value_type) * size(c);
}

}
