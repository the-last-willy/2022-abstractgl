#pragma once

#include "grid_indexing/at.hpp"
#include "grid.hpp"
#include "indexing.hpp"

namespace agl::common {

// Specialized overloads.

template<typename... G>
auto& at(
    const Grid<G...>& g,
    std::size_t i)
{
    return g.at(at(indexing(g), i));
}

template<typename... G>
auto& at(
    Grid<G...>& g,
    std::size_t i)
{
    return g.at(at(indexing(g), i));
}

template<typename... G>
auto& at(
    const Grid<G...>& g,
    std::size_t i,
    std::size_t j)
{
    return g.at(at(indexing(g), i, j));
}

template<typename... G>
auto& at(
    Grid<G...>& g,
    std::size_t i,
    std::size_t j)
{
    return g.at(at(indexing(g), i, j));
}

template<typename... G>
auto& at(
    const Grid<G...>& g,
    std::size_t i,
    std::size_t j,
    std::size_t k)
{
    return g.at(at(indexing(g), i, j, k));
}

template<typename... G>
auto& at(
    Grid<G...>& g,
    std::size_t i,
    std::size_t j,
    std::size_t k)
{
    return g.at(at(indexing(g), i, j, k));
}

}
