#pragma once

#include <array>
#include <vector>

namespace p983
{
    class Solution
    {
      public:
        int mincostTickets(std::vector<int>& days, std::vector<int>& costs)
        {
            std::array<int, 365> best_costs = {};

            std::array<bool, 365> critical_days = {};
            for (auto d : days)
                critical_days[size_t(d) - 1] = true;

            best_costs[0] = critical_days[0] ? std::min({costs[0], costs[1], costs[2]}) : 0;
            for (size_t i = 1; i < 365; ++i)
            {
                if (!critical_days[i])
                    best_costs[i] = best_costs[i - 1];
                else
                {
                    best_costs[i] = costs[0] + best_costs[i - 1];

                    best_costs[i] = std::min(best_costs[i], costs[1] + ((i >= 7) ? best_costs[i - 7] : 0));
                    best_costs[i] = std::min(best_costs[i], costs[2] + ((i >= 30) ? best_costs[i - 30] : 0));
                }
            }

            return best_costs.back();
        }
    };
}