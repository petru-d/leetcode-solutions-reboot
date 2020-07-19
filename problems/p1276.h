#pragma once
#include <vector>

namespace p1276
{
    class Solution
    {
      public:
        std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
        {
            int T = tomatoSlices;
            int C = cheeseSlices;

            if ((T % 2 == 1) || (C > T / 2) || (T / 2 > 2 * C))
                return {};

            return {T / 2 - C, 2 * C - T / 2};
        }
    };
}
