#pragma once
#include <vector>

namespace p1690
{
    class Solution
    {
      public:
        int stoneGameVII(std::vector<int>& stones)
        {
            _stones = std::move(stones);

            auto S = _stones.size();

            memo = std::vector<std::vector<int>>(S, std::vector<int>(S, -1));
            prefix = std::vector<int>(S, 0);

            int curr_sum = 0;
            for (size_t i = 0; i < S; ++i)
            {
                curr_sum += _stones[i];
                prefix[i] = curr_sum;
            }

            return min_diff(0, S - 1);
        }

        std::vector<int> _stones;
        std::vector<std::vector<int>> memo;
        std::vector<int> prefix;

        int sum(size_t l, size_t r)
        {
            return prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
        }

        int min_diff(size_t l, size_t r)
        {
            if (l == r)
            {
                // 1 stone left - Alice takes it for zero score and the game ends
                return 0;
            }
            if (l + 1 == r)
            {
                // 2 stones left - Alice will take the smallest (getting the biggest as score)
                // and bob will take the biggest (getting 0 score)
                return std::max(_stones[l], _stones[r]);
            }

            if (memo[l][r] != -1)
                return memo[l][r];

            auto alice_left_bob_left = sum(l + 1, r) - sum(l + 2, r) + min_diff(l + 2, r);
            auto alice_left_bob_right = sum(l + 1, r) - sum(l + 1, r - 1) + min_diff(l + 1, r - 1);

            auto alice_right_bob_left = sum(l, r - 1) - sum(l + 1, r - 1) + min_diff(l + 1, r - 1);
            auto alice_right_bob_right = sum(l, r - 1) - sum(l, r - 2) + min_diff(l, r - 2);

            auto alice_left = std::min(alice_left_bob_left, alice_left_bob_right);
            auto alice_right = std::min(alice_right_bob_left, alice_right_bob_right);

            auto result = std::max(alice_left, alice_right);

            // cout << l << " " << r << " " << result << endl;
            return memo[l][r] = result;
        }
    };

    class Solution2
    {
      public:
        int stoneGameVII(std::vector<int>& stones)
        {
            auto N = stones.size();
            std::vector<int> prefixSum(N + 1);

            for (size_t i = 0; i < N; ++i)
                prefixSum[i + 1] = prefixSum[i] + stones[i];

            std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));

            for (size_t length = 2; length <= N; ++length)
                for (size_t start = 0; start + length - 1 < N; ++start)
                {
                    auto end = start + length - 1;
                    int scoreRemoveFirst = prefixSum[end + 1] - prefixSum[start + 1];
                    int scoreRemoveLast = prefixSum[end] - prefixSum[start];

                    dp[start][end] = std::max(scoreRemoveFirst - dp[start + 1][end], scoreRemoveLast - dp[start][end - 1]);
                }

            return dp[0][N - 1];
        }
    };
}
