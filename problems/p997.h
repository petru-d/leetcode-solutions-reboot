#pragma once
#include <vector>
namespace p997
{
    class Solution
    {
      public:
        int findJudge(int N, std::vector<std::vector<int>>& trust)
        {
            std::vector<int> trusts(N, 0);

            for (const auto& t : trust)
            {
                trusts[t[0] - 1] = -1;

                if (trusts[t[1] - 1] == -1)
                    continue;

                ++trusts[t[1] - 1];
            }

            for (size_t t = 0; t < N; ++t)
            {
                if (trusts[t] == N - 1)
                    return static_cast<int>(t + 1);
            }

            return -1;
        }
    };
}