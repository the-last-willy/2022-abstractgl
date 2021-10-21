#pragma once

#include "mesh/geometry.hpp"
#include "index.hpp"
#include "mesh.hpp"
#include "proxy.hpp"

namespace agl::engine {

inline
uint32_t material_id(ConstFaceProxy cfp) {
    return geometry(mesh(cfp)).face_material_ids[index(cfp)];
}

inline
uint32_t& material_id(MutableFaceProxy mfp) {
    return geometry(mesh(mfp)).face_material_ids[index(mfp)];
}

}
