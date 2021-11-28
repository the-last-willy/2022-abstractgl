#pragma once

namespace agl::standard {

template<typename Container>
requires requires(Container c) {
    c.reserve(std::size_t());
    size(c);
} 
void reserve_more(Container& c, std::size_t n) {
    c.reserve(size(c) + n);
}

}
