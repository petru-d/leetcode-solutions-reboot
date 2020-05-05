#pragma once
#include <algorithm>
#include <vector>

namespace p1029
{
    class Solution
    {
      public:
        int twoCitySchedCost(std::vector<std::vector<int>>& costs)
        {
            std::sort(costs.begin(), costs.end(),
                      [](const std::vector<int>& l, const std::vector<int>& r) { return (abs(l[0] - l[1]) > abs(r[0] - r[1])); });

            int result = 0;

            size_t C = costs.size();

            size_t going_a = 0;
            size_t going_b = 0;

            size_t i = 0;
            for (i = 0; i < C; ++i)
            {
                if (costs[i][0] <= costs[i][1])
                {
                    ++going_a;
                    result += costs[i][0];
                }
                else
                {
                    ++going_b;
                    result += costs[i][1];
                }
                if (going_a == C / 2 || going_b == C / 2)
                    break;
            }
            for (size_t j = i + 1; j < C; ++j)
            {
                result += (going_a < C / 2) ? costs[j][0] : costs[j][1];
            }

            return result;
        }
    };
}