#pragma once
#include <array>
#include <utility>
#include <vector>

namespace p935
{
    constexpr int M = 1000000007;

    class Solution
    {
      public:
        int knightDialer(int n)
        {
            memo = std::vector<std::vector<int>>(size_t(n), std::vector<int>(10, -1));

            int result = 0;
            for (int i = 0; i <= 9; ++i)
            {
                result += dial(n, i);
                result %= M;
            }

            return result;
        }

      private:
        int dial(int n, int start)
        {
            if (n == 1)
                return 1;

            auto m = memo[size_t(n) - 1][start];
            if (m != -1)
                return m;

            int result = 0;
            const auto& edge = edges[start];
            for (auto e : edge)
            {
                result += dial(n - 1, e);
                result %= M;
            }
            memo[size_t(n) - 1][start] = result;
            return result;
        };

        std::vector<std::vector<int>> memo;
        std::array<std::vector<int>, 10> edges = {std::vector<int>{4, 6},    std::vector<int>{6, 8},    std::vector<int>{7, 9},
                                                  std::vector<int>{4, 8},    std::vector<int>{0, 3, 9}, std::vector<int>{},
                                                  std::vector<int>{0, 1, 7}, std::vector<int>{2, 6},    std::vector<int>{1, 3},
                                                  std::vector<int>{2, 4}};
    };
}
