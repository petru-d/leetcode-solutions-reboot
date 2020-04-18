#pragma once
#include <algorithm>
#include <vector>

namespace p64
{
    class Solution
    {
      public:
        int minPathSum(std::vector<std::vector<int>>& grid)
        {
            if (grid.empty())
                return 0;

            size_t N = grid.size();
            size_t M = grid.front().size();

            for (size_t i = 1; i < N; ++i)
                grid[i][0] += grid[i - 1][0];
            for (size_t j = 1; j < M; ++j)
                grid[0][j] += grid[0][j - 1];

            for (size_t i = 1; i < N; ++i)
                for (size_t j = 1; j < M; ++j)
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);

            return grid[N - 1][M - 1];
        }
    };
}