#pragma once

#include "radian_per_revolution.hpp"
#include "revolution_per_degree.hpp"

namespace agl::constant {

constexpr auto radian_per_degree
= radian_per_revolution * revolution_per_degree;

}
