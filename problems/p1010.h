#pragma once
#include <vector>
#include <array>

namespace p1010
{
    class Solution
    {
      public:
        int numPairsDivisibleBy60(std::vector<int>& time)
        {
            size_t T = time.size();
            if (T < 2)
                return 0;

            std::array<int, 60> rems = {};
            for (const auto t : time)
                ++rems[t % 60];

            int total = 0;
            for (size_t i = 1; i < 30; ++i)
                total += rems[i] * rems[60 - i];
            if (rems[30] > 0)
                total += rems[30] * (rems[30] - 1) / 2;
            if (rems[0] > 0)
                total += rems[0] * (rems[0] - 1) / 2;

            return total;
        }
    };
}
