#pragma once

#include <limits>

namespace p50
{
    class Solution
    {
      public:
        double myPow(double x, int n)
        {
            bool negative = n < 0;
            bool minint = (n == std::numeric_limits<int>::min());

            if (minint)
                ++n;
            if (negative)
                n = -n;

            auto res = pos_pow(x, n);

            if (negative)
                res = 1 / res;
            if (minint)
                res /= x;

            return res;
        }

      private:
        double pos_pow(double x, int n)
        {
            if (n == 0)
                return 1;

            if (n % 2 == 0)
            {
                auto pp = pos_pow(x, n / 2);
                return pp * pp;
            }

            auto pp = pos_pow(x, (n - 1) / 2);
            return x * pp * pp;
        }
    };
}
