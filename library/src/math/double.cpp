
#include "math/double.hpp"

namespace my::math
{
    // great article for this logic from https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
    bool almostEqual(double a, double b, double tolerance, uint64_t ulps)
    {
        if (std::isnan(a) || std::isnan(b))
        {
            return false;
        }
        if (std::isinf(a) || std::isinf(b))
        {
            return a == b;
        }
        if ((a < 0) != (b < 0))
        {
            return false;
        }

        // case absolute epsilon check: values near zero
        double diff = std::abs(a - b);
        if (diff <= tolerance)
        {
            return true;
        }

        // case relative ulp check: large numbers
        uint64_t ua = std::bit_cast<uint64_t>(a);
        uint64_t ub = std::bit_cast<uint64_t>(b);

        uint64_t ulpsDiff = (ua > ub) ? (ua - ub) : (ub - ua);

        return ulpsDiff <= ulps;
    }
}