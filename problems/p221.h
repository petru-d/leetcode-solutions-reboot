#pragma once
#include <algorithm>
#include <vector>

namespace p221
{
    class Solution
    {
      public:
        int maximalSquare(std::vector<std::vector<char>>& matrix)
        {
            uint16_t best = 0;

            size_t N = matrix.size();
            size_t M = (N != 0 ? matrix.front().size() : 0);

            std::vector<std::vector<uint16_t>> dp(N, std::vector<uint16_t>(M, 0));

            for (size_t i = 0; i < N; ++i)
            {
                dp[i][0] = matrix[i][0] - '0';
                if (dp[i][0] == 1)
                    best = 1;
            }
            for (size_t j = 0; j < M; ++j)
            {
                dp[0][j] = matrix[0][j] - '0';
                if (dp[0][j] == 1)
                    best = 1;
            }

            for (size_t i = 1; i < N; ++i)
                for (size_t j = 1; j < M; ++j)
                {
                    if (matrix[i][j] == '0')
                        continue;

                    uint16_t n_val = dp[i - 1][j];
                    uint16_t e_val = dp[i][j - 1];
                    uint16_t ne_val = dp[i - 1][j - 1];

                    dp[i][j] = 1 + std::min(n_val, std::min(e_val, ne_val));

                    best = std::max(best, dp[i][j]);
                }

            return static_cast<int>(best * best);
        }
    };
}