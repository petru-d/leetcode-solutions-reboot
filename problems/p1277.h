#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

namespace p1277
{
    class Solution
    {
      public:
        int countSquares(std::vector<std::vector<int>>& matrix)
        {
            auto dp = matrix[0];

            int result = std::accumulate(dp.begin(), dp.end(), 0);

            size_t L = matrix.size();
            size_t C = matrix.front().size();

            auto dp_new = std::vector(dp.size(), 0);
            for (size_t i = 1; i < L; ++i)
            {
                dp_new[0] = matrix[i][0];
                result += dp_new[0];

                for (size_t j = 1; j < C; ++j)
                {
                    dp_new[j] = (0 == matrix[i][j]) ? 0 : 1 + std::min({dp[j], dp_new[j - 1], dp[j - 1]});
                    result += dp_new[j];
                }

                std::swap(dp, dp_new);
            }
            return result;
        }
    };
}