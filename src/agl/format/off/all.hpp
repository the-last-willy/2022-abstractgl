#pragma once

#include <agl/all.hpp>
#include <agl/standard/all.hpp>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace format::off {

struct File {
    std::vector<agl::Uvec3> triangle_indices = {};
    std::vector<agl::Vec3> vertex_positions = {};
};

inline
auto read(const std::string& filepath) {
    auto f = File();

    auto stream = std::stringstream(
        agl::standard::string(std::filesystem::path(filepath)));

    if(stream.peek() == 'O') {
        stream.ignore(4, '\n');
    }

    std::size_t vertex_count;
    stream >> vertex_count;
    f.vertex_positions.resize(vertex_count);

    std::size_t face_count;
    stream >> face_count;
    f.triangle_indices.reserve(face_count);
    
    std::size_t edge_count;
    stream >> edge_count;

    for(std::size_t i = 0; i < vertex_count; ++i) {
        auto& vp = f.vertex_positions[i];
        stream >> vp[0] >> vp[1] >> vp[2];
    }

    auto face_indices = std::vector<uint32_t>();
    for(std::size_t i = 0; i < face_count; ++i) {
        GLuint face_vertex_count;
        stream >> face_vertex_count;
        if(face_vertex_count >= size(face_indices)) {
            face_indices.resize(face_vertex_count);
        }
        for(GLuint j = 0; j < face_vertex_count; ++j) {
            stream >> face_indices[j];
        }
        for(GLuint j = 2; j < face_vertex_count; ++j) {
            f.triangle_indices.emplace_back(agl::Uvec3{
                face_indices[0], face_indices[j - 1], face_indices[j]});
        }
    }

    return f;
}

};
