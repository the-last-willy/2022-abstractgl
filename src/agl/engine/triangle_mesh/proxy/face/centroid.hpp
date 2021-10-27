#pragma once

#include "vertex/all.hpp"
#include "incident_vertex_count.hpp"
#include "incident_vertex.hpp"
#include "proxy.hpp"

namespace agl::engine {

inline
agl::Vec3 centroid(ConstFaceProxy cfp) {
    auto c = incident_vertex_count(cfp);
    auto sum = agl::vec3(0.f);
    for(uint32_t i = 0; i < c; ++i) {
        sum += position(incident_vertex(cfp, i));
    }
    return sum / float(c);
}

}
