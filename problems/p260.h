#pragma once

#include <vector>

namespace p260
{
    class Solution
    {
      public:
        std::vector<int> singleNumber(std::vector<int>& nums)
        {
            int axb = 0;
            for (const auto n : nums)
                axb ^= n;

            size_t b = 0;
            for (size_t i = 0; i < 32; ++i)
                if (axb & (1 << i))
                {
                    b = i;
                    break;
                }

            int with_bit = 0;
            for (const auto n : nums)
                if (n & (1 << b))
                    with_bit ^= n;

            return {with_bit, axb ^ with_bit};
        }
    };
}
