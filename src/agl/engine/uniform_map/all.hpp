#pragma once

#include "program.hpp"
#include "uniform.hpp"

#include <memory>
#include <string>

namespace agl::engine {

template<typename T>
struct AnyUniform : AnyUniform<void> {
    void upload_to(eng::Program& p, agl::UniformIndex ui) const override {
        agl::uniform(p.program, ui, value);
    }   

    T value;
};

template<>
struct AnyUniform<void> {
    virtual ~AnyUniform() = default;

    virtual void upload_to(eng::Program&, agl::UniformIndex) const = 0;
};

struct UniformMap {
    std::map<std::string, std::unique_ptr<AnyUniform<void>>> mapping;
};

template<typename T>
void assign(UniformMap& um, std::string name, T&& t) {
    um.mapping[std::move(name)]
    = std::make_unique<AnyUniform<T>>(std::move(t));
}

inline
void upload_to(const UniformMap&, eng::Program&) {

}

}
