#pragma once

#include "topology/face/incident_vertex.hpp"
#include "vertex/proxy.hpp"
#include "index.hpp"
#include "proxy.hpp"
#include "topology.hpp"

namespace agl::engine {

inline
ConstVertexProxy incident_vertex(ConstFaceProxy ctp, uint32_t i) {
    return ConstVertexProxy(
        mesh(ctp),
        incident_vertex(topology(ctp), i));
}

inline
MutableVertexProxy incident_vertex(MutableFaceProxy mtp, uint32_t i) {
    return MutableVertexProxy(
        mesh(mtp),
        incident_vertex(topology(mtp), i));
}

}
