#pragma once
#include <cmath>
#include <cstdint>
#include <limits>
namespace p29
{
    class Solution
    {
      public:
        int divide(int dividend, int divisor)
        {
            if (0 == divisor)
                return std::numeric_limits<int>::max();
            if (1 == divisor)
                return dividend;
            if (-1 == divisor && dividend == std::numeric_limits<int>::min())
                return std::numeric_limits<int>::max();
            if (-1 == divisor)
                return -dividend;

            bool change_sign = dividend < 0 != divisor < 0;
            int64_t l_dividend = llabs(dividend);
            int64_t l_divisor = llabs(divisor);

            int result = 0;
            while (l_dividend >= l_divisor)
            {
                int64_t temp = l_divisor;
                int current_fit = 1;
                while (l_dividend >= (temp << 1))
                {
                    temp <<= 1;
                    current_fit <<= 1;
                }
                result += current_fit;
                l_dividend -= temp;
            }

            return change_sign ? -result : result;
        }
    };
}
