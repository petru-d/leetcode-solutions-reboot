#pragma once
#include <cmath>

namespace p326
{
    class Solution2
    {
      public:
        double log_base(double base, double x)
        {
            return std::log(x) / log(base);
        }

        bool isPowerOfThree(int n)
        {
            auto l3 = log_base(3, n);

            return std::abs(l3 - std::round(l3)) < 0.00000000001;
        }
    };

    class Solution
    {
      public:
        bool isPowerOfThree(int n)
        {
            // is 3^19 divisible by n ? then it's a power of 3
            return n > 0 && 1162261467 % n == 0;
        }
    };

}
