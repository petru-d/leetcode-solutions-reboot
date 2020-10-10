#pragma once
#include <vector>

namespace p1217
{
    class Solution
    {
      public:
        int minCostToMoveChips(std::vector<int>& position)
        {
            int odds = 0;
            int evens = 0;

            for (auto p : position)
                if (p % 2 == 0)
                    ++evens;
                else
                    ++odds;

            return std::min(evens, odds);
        }
    };
}
