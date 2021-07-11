#pragma once
#include <string>
#include <vector>

namespace p97
{
    class Solution2
    {
      public:
        bool isInterleave(std::string s1, std::string s2, std::string s3)
        {
            S = std::move(s3);
            A = std::move(s1);
            B = std::move(s2);

            SS = S.size();
            AA = A.size();
            BB = B.size();

            if (AA + BB != SS)
                return false;

            if (AA == 0)
                return B == S;
            if (BB == 0)
                return A == S;

            memo = std::vector<int8_t>((SS + 1) * (AA + 1) * (BB + 1));

            return solve(0, 0, 0);
        }

        bool solve(size_t n, size_t i, size_t j)
        {
            if (memo[n * SS + i * AA + j] != 0)
                return memo[n * SS + i * AA + j] == 1;

            if (n == SS && i == AA && j == BB)
            {
                memo[n * SS + i * AA + j] = 1;
                return true;
            }

            if (n == S.size())
            {
                memo[n * SS + i * AA + j] = -1;
                return false;
            }

            bool take_from_A = false;
            if (i < A.size() && A[i] == S[n])
                take_from_A = solve(n + 1, i + 1, j);

            bool take_from_B = false;
            if (j < B.size() && B[j] == S[n])
                take_from_B = solve(n + 1, i, j + 1);

            bool result = take_from_A || take_from_B;

            memo[n * SS + i * AA + j] = result ? 1 : -1;

            return result;
        }

        // 0 for unknown, -1 for no, 1 for yes
        std::vector<int8_t> memo;

        std::string S;
        std::string A;
        std::string B;
        size_t SS = -1;
        size_t AA = -1;
        size_t BB = -1;
    };

    class Solution
    {
      public:
        bool isInterleave(std::string s1, std::string s2, std::string s3)
        {
            auto S3 = s3.size();
            auto S1 = s1.size();
            auto S2 = s2.size();

            if (s3.size() != s1.size() + s2.size())
                return false;

            std::vector<uint8_t> dp(S2 + 1, 0);
            std::vector<uint8_t> new_dp(S2 + 1, 0);

            for (size_t i = 0; i <= S1; ++i)
            {
                for (size_t j = 0; j <= S2; ++j)
                {
                    if (i == 0 && j == 0)
                    {
                        new_dp[j] = 1;
                    }
                    else if (i == 0)
                    {
                        new_dp[j] = new_dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                    }
                    else if (j == 0)
                    {
                        new_dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                    }
                    else
                    {
                        new_dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (new_dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                    }
                }
                std::swap(dp, new_dp);
            }

            return dp[S2] == 1;
        }
    };
}
