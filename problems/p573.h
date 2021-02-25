#pragma once
#include <cmath>
#include <limits>
#include <vector>

namespace p573
{
    class Solution
    {
      public:
        int minDistance(int height, int width, std::vector<int>& tree, std::vector<int>& squirrel,
                        std::vector<std::vector<int>>& nuts)
        {
            auto dist = [](const std::vector<int>& p1, const std::vector<int>& p2) {
                return (std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]));
            };

            int max_gain = std::numeric_limits<int>::min();
            auto& the_nut = nuts[0];
            int total = 0;
            for (const auto& n : nuts)
            {
                auto gain = -dist(squirrel, n) + dist(n, tree);
                if (max_gain < gain)
                {
                    max_gain = gain;
                    the_nut = n;
                }
                total += 2 * dist(n, tree);
            }

            return total + dist(squirrel, the_nut) - dist(tree, the_nut);
        }
    };
}
