#pragma once

#include "degree_per_revolution.hpp"
#include "revolution_per_radian.hpp"

namespace agl::constant {

constexpr auto degree_per_radian
= degree_per_revolution * revolution_per_radian;

}
