#pragma once
#include <cmath>
#include <cstdint>

namespace p441
{
    class Solution
    {
      public:
        int arrangeCoins(int n)
        {
            return static_cast<int>(std::floor((std::sqrt(1 + 8 * static_cast<uint64_t>(n)) - 1) / 2));
        }
    };
}
