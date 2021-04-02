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

    class Solution2
    {
      public:
        int findMaxForm(std::vector<std::string>& strs, int m, int n)
        {
            auto Z = strs.size();

            struct ZeroOne
            {
                size_t Zero = 0;
                size_t One = 0;
            };
            std::vector<ZeroOne> zeroOnes;
            zeroOnes.reserve(Z);

            for (const auto& s : strs)
            {
                ZeroOne zo;
                for (auto c : s)
                    if (c == '0')
                        ++zo.Zero;
                    else
                        ++zo.One;
                zeroOnes.push_back(std::move(zo));
            }

            std::vector<std::vector<size_t>> old_dp(m + 1, std::vector<size_t>(n + 1, 0));
            std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

            for (size_t row = 0; row <= m; ++row)
                for (size_t col = 0; col <= n; ++col)
                    if (zeroOnes[0].Zero <= row && zeroOnes[0].One <= col)
                        old_dp[row][col] = 1;

            for (size_t zo = 1; zo < Z; ++zo)
            {
                for (size_t row = 0; row <= m; ++row)
                    for (size_t col = 0; col <= n; ++col)
                    {
                        size_t upper_left = 0;
                        if (row >= zeroOnes[zo].Zero && col >= zeroOnes[zo].One)
                            upper_left = 1 + old_dp[row - zeroOnes[zo].Zero][col - zeroOnes[zo].One];
                        dp[row][col] = std::max(old_dp[row][col], upper_left);
                    }

                std::swap(dp, old_dp);
            }

            return old_dp[m][n];
        }
    };
}
