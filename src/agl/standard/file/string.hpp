#pragma once

#include <filesystem>
#include <fstream>
#include <string>

namespace agl::standard {

inline
std::string string(const std::filesystem::path& p) {
    auto ifs = std::ifstream(p);
    if(ifs.fail()) {
        throw std::runtime_error(
            std::string("Failed to openg file \"") + p.string() + "\".");
    }
    return std::string(
        std::istreambuf_iterator<char>(ifs),
        std::istreambuf_iterator<char>());
}

}
