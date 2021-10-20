#pragma once

#include "geometry/all.hpp"
#include "proxy/vertex/proxy.hpp"
#include "topology/mesh/create_vertex.hpp"
#include "geometry.hpp"
#include "mesh.hpp"

namespace agl::engine {

inline
MutableVertexProxy create_vertex(TriangleMesh& tm) {
    create_vertex(topology(tm));
    return MutableVertexProxy(
        tm,
        create_vertex(geometry(tm)));
}

}
