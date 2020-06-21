#pragma once

#include <algorithm>
#include <vector>

namespace p174
{
    class Solution
    {
      public:
        int calculateMinimumHP(std::vector<std::vector<int>>& dungeon)
        {
            if (dungeon.empty() || dungeon.front().empty())
                return 0;

            size_t r = dungeon.size();
            size_t c = dungeon.front().size();

            auto dp = dungeon;

            for (size_t i = r; i >= 1; --i)
                for (size_t j = c; j >= 1; --j)
                {
                    if (i != r && j != c)
                    {
                        int south = dp[i][j - 1];
                        int east = dp[i - 1][j];
                        dp[i - 1][j - 1] = std::min(0, dungeon[i - 1][j - 1] + std::max(south, east));
                    }
                    else if (i != r)
                    {
                        int south = dp[i][j - 1];
                        dp[i - 1][j - 1] = std::min(0, dungeon[i - 1][j - 1] + south);
                    }
                    else if (j != c)
                    {
                        int east = dp[i - 1][j];
                        dp[i - 1][j - 1] = std::min(0, dungeon[i - 1][j - 1] + east);
                    }
                    else
                    {
                        dp[i - 1][j - 1] = std::min(0, dungeon[i - 1][j - 1]);
                    }
                }

            return 1 - dp[0][0];
        }
    };
}
