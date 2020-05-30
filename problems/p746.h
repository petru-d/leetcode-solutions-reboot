#pragma once

#include <algorithm>
#include <vector>

namespace p746
{
    class Solution
    {
      public:
        int minCostClimbingStairs(std::vector<int>& cost)
        {
            size_t N = cost.size();
            if (N <= 2)
                return 0;

            std::vector<int> min_cost(N + 1, 0);

            min_cost[0] = 0;
            min_cost[1] = 0;
            for (size_t i = 2; i < N + 1; ++i)
            {
                min_cost[i] = std::min(cost[i - 2] + min_cost[i - 2], cost[i - 1] + min_cost[i - 1]);
            }

            return min_cost[N];
        }
    };
}