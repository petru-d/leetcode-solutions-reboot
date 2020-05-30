#pragma once

#include <algorithm>
#include <vector>

namespace p322
{
    class Solution
    {
      public:
        int coinChange(std::vector<int>& coins, int amount)
        {
            size_t A = amount;

            std::vector<size_t> dp(A + 1, std::numeric_limits<int>::max());
            dp[0] = 0;

            for (size_t i = 1; i <= A; ++i)
                for (size_t c = 0; c < coins.size(); ++c)
                    if (i >= coins[c])
                        dp[i] = std::min(dp[i], dp[i - coins[c]] + 1);

            auto res = dp.back();

            return res == std::numeric_limits<int>::max() ? -1 : res;
        }
    };
}