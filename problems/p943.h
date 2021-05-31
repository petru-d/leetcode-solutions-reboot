#pragma once
#include <string>
#include <vector>

namespace p943
{
    class Solution
    {
      public:
        std::string shortestSuperstring(std::vector<std::string>& words)
        {
            // 1. precompute the overlaps
            auto W = words.size();
            auto overlaps = std::vector<std::vector<size_t>>(W, std::vector<size_t>(W, 0));
            for (size_t i = 0; i < W; ++i)
                for (size_t j = 0; j < W; ++j)
                    if (i != j)
                        overlaps[i][j] = get_overlap(words[i], words[j]);

            std::vector<std::vector<std::string>> dp(1 << W, std::vector<std::string>(W));

            // 2. set inital val for dp
            for (size_t i = 0; i < W; ++i)
                dp[1 << i][i] += words[i];

            // 3. fill the dp
            for (size_t mask = 1; mask < (1 << W); ++mask)
                for (size_t j = 0; j < W; ++j)
                    if (mask & (1 << j))
                        for (size_t i = 0; i < W; ++i)
                            if (i != j && (mask & (1 << i)))
                            {
                                std::string tmp = dp[mask ^ (1 << j)][i] + words[j].substr(overlaps[i][j]);
                                if (dp[mask][j].empty() || tmp.size() < dp[mask][j].size())
                                    dp[mask][j] = tmp;
                            }

            // 4. get the result
            std::string res = dp[(1 << W) - 1][0];
            for (size_t i = 1; i < W; ++i)
                if (dp[(1 << W) - 1][i].size() < res.size())
                {
                    res = dp[(1 << W) - 1][i];
                }

            return res;
        }

        size_t get_overlap(const std::string& first, const std::string& second)
        {
            auto max_i = std::min(first.size(), second.size());

            std::string first_trimmed = first.substr(first.size() - max_i);
            std::string second_trimmed = second.substr(0, max_i);

            for (auto m = max_i; m > 1; --m)
            {
                auto test_overlap = m - 1;

                if (first.substr(first.size() - test_overlap) == second.substr(0, test_overlap))
                    return test_overlap;
            }

            return 0;
        }
    };
}
