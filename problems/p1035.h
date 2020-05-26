#pragma once
#include <algorithm>
#include <vector>

namespace p1035
{
    class Solution
    {
      public:
        int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B)
        {

            std::vector<std::vector<int>> dp(A.size(), std::vector<int>(B.size(), 0));

            for (size_t i = 0; i < A.size(); ++i)
            {
                for (size_t j = 0; j < B.size(); ++j)
                {
                    int north = (i == 0) ? 0 : dp[i - 1][j];
                    int east = (j == 0) ? 0 : dp[i][j - 1];
                    int north_east = (i != 0 && j != 0) ? dp[i - 1][j - 1] : 0;

                    dp[i][j] = std::max({north, east, ((A[i] == B[j]) ? 1 : 0) + north_east});
                }
            }

            return dp.back().back();
        }
    };
}