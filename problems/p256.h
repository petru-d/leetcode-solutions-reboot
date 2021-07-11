#pragma once
#include <vector>

namespace p256
{
    class Solution
    {
      public:
        int minCost(std::vector<std::vector<int>>& costs)
        {
            auto min_costs = costs;

            auto C = min_costs.size();
            for (size_t i = 1; i < C; ++i)
            {
                min_costs[i][0] = costs[i][0] + std::min(min_costs[i - 1][1], min_costs[i - 1][2]);
                min_costs[i][1] = costs[i][1] + std::min(min_costs[i - 1][0], min_costs[i - 1][2]);
                min_costs[i][2] = costs[i][2] + std::min(min_costs[i - 1][1], min_costs[i - 1][0]);
            }

            return *std::min_element(min_costs[C - 1].cbegin(), min_costs[C - 1].cend());
        }
    };
}
