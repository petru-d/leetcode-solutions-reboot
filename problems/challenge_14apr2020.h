#pragma once
#include <string>
#include <vector>

namespace challenge_14apr2020
{
    class Solution
    {
      public:
        std::string stringShift(std::string s, std::vector<std::vector<int>>& shift)
        {
            int total_shift = 0;
            for (const auto& sh : shift)
            {
                if (sh[0] == 0)
                    total_shift -= sh[1];
                if (sh[0] == 1)
                    total_shift += sh[1];
            }

            if (total_shift == 0)
                return s;

            // normalize
            total_shift %= static_cast<int>(s.size());

            // transform to right shift
            if (total_shift < 0)
                total_shift += static_cast<int>(s.size());

            auto p1 = s.substr(s.size() - total_shift);
            auto p2 = s.substr(0, s.size() - total_shift);

            return p1 + p2;
        }
    };
}