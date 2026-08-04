#pragma once

#include <bit>
#include <cmath>
#include <stdint.h>

namespace my::math
{
    bool almostEqual(double a, double b, double tolerance = 1e-12, uint64_t ulps = 4);
}