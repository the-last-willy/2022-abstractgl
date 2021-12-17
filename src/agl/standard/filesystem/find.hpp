#pragma once

#include <optional>
#include <filesystem>

namespace agl::standard {

inline
auto try_find(
    const std::filesystem::path& what,
    std::filesystem::path location = std::filesystem::current_path())
-> std::optional<std::filesystem::path>
{
    while(not location.empty()) {
        if(exists(location / what)) {
            return location;
        }
        location = location.parent_path();
    }
    return std::nullopt;
}

}
