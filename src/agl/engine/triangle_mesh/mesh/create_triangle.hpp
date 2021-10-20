#pragma once

#include "geometry/all.hpp"
#include "proxy/triangle/proxy.hpp"
#include "geometry.hpp"
#include "mesh.hpp"

namespace agl::engine {

inline
MutableTriangleProxy create_triangle(TriangleMesh& tm) {
    return MutableTriangleProxy(
        tm,
        create_vertex(geometry(tm)));
}

}
