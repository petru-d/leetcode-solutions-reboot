#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace p474
{
    class Solution
    {
      public:
        int findMaxForm(std::vector<std::string>& strs, int m, int n)
        {
            if (strs.empty())
                return 0;

            auto Z = static_cast<size_t>(m);
            auto O = static_cast<size_t>(n);
            auto K = strs.size();

            std::vector<std::vector<int>> dp_prev(Z + 1, std::vector<int>(O + 1, 0));
            for (size_t k = 0; k < K; ++k)
            {
                int zeros_k = 0;
                int ones_k = 0;

                std::for_each(strs[k].cbegin(), strs[k].cend(), [&zeros_k, &ones_k](char c) { c == '0' ? ++zeros_k : ++ones_k; });

                for (size_t z = Z + 1; z >= size_t(zeros_k) + 1; --z)
                    for (size_t o = O + 1; o >= size_t(ones_k) + 1; --o)
                        dp_prev[z - 1][o - 1] = std::max(dp_prev[z - 1][o - 1], 1 + dp_prev[z - 1 - zeros_k][o - 1 - ones_k]);
            }

            return dp_prev[Z][O];
        }
    };
}
