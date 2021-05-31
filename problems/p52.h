#pragma once
#include <vector>

namespace p52
{
    class Solution
    {
      public:
        int totalNQueens(int n)
        {
            std::vector<size_t> sol;
            int total = 0;
            go(size_t(n), sol, total);

            return total;
        }

        void go(size_t N, std::vector<size_t>& curr, int& total)
        {
            if (curr.size() == N)
            {
                ++total;
                return;
            }

            auto can_place = [&](size_t at_col) {
                auto C = curr.size();
                for (size_t i = 0; i < C; ++i)
                {
                    // {i, curr[i]} and {C, at_col}
                    if (curr[i] == at_col)
                        return false;
                    // i + k == C && curr[i] + k == at_col
                    if (C - i == at_col - curr[i] || C - i == curr[i] - at_col)
                        return false;
                }
                return true;
            };

            for (size_t i = 0; i < N; ++i)
                if (can_place(i))
                {
                    curr.push_back(i);
                    go(N, curr, total);
                    curr.pop_back();
                }
        }
    };
}
