#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p72
{
    class Solution
    {
      public:
        int minDistance(std::string word1, std::string word2)
        {
            size_t W1 = word1.size();
            size_t W2 = word2.size();
            if (W2 < W1)
            {
                std::swap(word1, word2);
                std::swap(W1, W2);
            }
            if (0 == W1)
                return int(W2);

            std::vector<uint16_t> curr_dp(W1, 0);
            curr_dp[0] = word1.front() == word2.front() ? 0 : 1;
            for (size_t w1 = 1; w1 < W1; ++w1)
            {
                curr_dp[w1] = curr_dp[w1 - 1] + (word2.front() == word1[w1] ? 0 : 1);
            }
            std::vector<uint16_t> next_dp(W1, 0);

            for (size_t w2 = 1; w2 < W2; ++w2)
            {
                for (size_t w1 = 0; w1 < W1; ++w1)
                {
                    uint16_t west = (w1 != 0) ? uint64_t(next_dp[w1 - 1]) + 1 : uint16_t(w2 + 1);

                    uint16_t north_west = (w1 != 0) ? curr_dp[w1 - 1] : uint16_t(w2);
                    north_west += (word1[w1] != word2[w2] ? 1 : 0);

                    uint16_t north = 1 + curr_dp[w1];

                    next_dp[w1] = std::min({west, north_west, north});
                }
                std::swap(curr_dp, next_dp);
            }

            return curr_dp.back();
        }
    };
}