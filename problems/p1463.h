#pragma once
#include <vector>

namespace p1463
{
    class Solution
    {
      public:
        int cherryPickup(std::vector<std::vector<int>>& grid)
        {
            size_t R = grid.size();
            size_t C = grid[0].size();

            std::vector<std::vector<int>> memo(C, std::vector<int>(C, 0));
            for (size_t i = 0; i < C; ++i)
                for (size_t j = 0; j < C;++j)
                {
                    memo[i][j] = (i == j) ? grid[R - 1][i] : grid[R - 1][i] + grid[R - 1][j];
                }

            auto new_memo = memo;

            for (size_t k = R - 1; k >= 1; --k)
            {
                size_t row = k - 1;

                // calculate "row" from "row + 1"
                for (size_t i = 0; i < C; ++i)
                    for (size_t j = 0; j < C; ++j)
                    {
                        new_memo[i][j] = (i == j) ? grid[row][i] : grid[row][i] + grid[row][j];

                        int ll = (i > 0 && j > 0) ? memo[i - 1][j - 1] : 0;
                        int lc = (i > 0) ? memo[i - 1][j] : 0;
                        int lr = (i > 0 && j < C - 1) ? memo[i - 1][j + 1] : 0;

                        int cl = (j > 0) ? memo[i][j - 1] : 0;
                        int cc = memo[i][j];
                        int cr = (j < C - 1) ? memo[i][j + 1] : 0;

                        int rl = (i < C - 1 && j > 0) ? memo[i + 1][j - 1] : 0;
                        int rc = (i < C - 1 ) ? memo[i + 1][j ] : 0;
                        int rr = (i < C - 1 && j < C-1) ? memo[i + 1][j + 1] : 0;

                        new_memo[i][j] += std::max({ll, lc, lr, cl, cc, cr, rl, rc, rr});
                    }

                std::swap(new_memo, memo);
            }

            return memo[0][C - 1];
        }
    };
}
