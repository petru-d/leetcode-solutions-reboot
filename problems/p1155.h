#pragma once
#include <algorithm>
#include <vector>

namespace p1155
{
    class Solution
    {
      public:
        int numRollsToTarget(int d, int f, int target)
        {

            // dp[dd][tt] represents how many ways we can achieve tt + 1 with dd + 1 dice
            std::vector<std::vector<int>> dp(size_t(d), std::vector<int>(size_t(target), 0));

            for (size_t tt = 0; tt < std::min(size_t(f), size_t(target)); ++tt)
                dp[0][tt] = 1;

            for (size_t dd = 1; dd < size_t(d); ++dd)
                for (size_t tt = 1; tt < size_t(target); ++tt)
                    for (int ff = 1; ff <= f; ++ff)
                    {
                        if (tt < ff)
                            break;
                        dp[dd][tt] += dp[dd - 1][tt - ff];
                        dp[dd][tt] %= 1000000007;
                    }

            return dp.back().back();
        }
    };
}
