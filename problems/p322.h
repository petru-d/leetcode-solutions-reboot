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

            return res == std::numeric_limits<int>::max() ? -1 : static_cast<int>(res);
        }

        int coinChange2(std::vector<int>& coins, int amount)
        {
            if (0 == amount)
                return 0;

            std::sort(coins.rbegin(), coins.rend());

            std::vector<int> change(size_t(amount) + 1, -1);
            change[0] = 0;
            for (size_t i = 1; i < change.size(); ++i)
            {
                if (i % coins[0] == 0)
                {
                    change[i] = i / coins[0];
                    continue;
                }

                auto best = std::numeric_limits<int>::max();
                for (auto c : coins)
                {
                    if (c <= i && change[i - c] != -1)
                    {
                        best = std::min(best, change[i - c] + 1);
                    }
                }
                if (best != std::numeric_limits<int>::max())
                {
                    change[i] = best;
                }
            }

            return change.back();
        }
    };
}