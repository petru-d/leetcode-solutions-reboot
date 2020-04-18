#pragma once
#include <vector>

namespace p200
{
    class Solution
    {
      public:
        int numIslands(std::vector<std::vector<char>>& grid)
        {
            if (grid.empty())
                return 0;

            size_t N = grid.size();
            size_t M = grid.front().size();

            int islands_count = 0;
            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < M; ++j)
                    if (grid[i][j] == '1')
                    {
                        ++islands_count;
                        flood(grid, N, M, i, j);
                    }

            return islands_count;
        }

      private:
        void flood(std::vector<std::vector<char>>& grid, size_t N, size_t M, size_t x, size_t y)
        {
            grid[x][y] = '2';

            if (x > 0 && grid[x - 1][y] == '1')
                flood(grid, N, M, x - 1, y);
            if (x < N - 1 && grid[x + 1][y] == '1')
                flood(grid, N, M, x + 1, y);
            if (y > 0 && grid[x][y - 1] == '1')
                flood(grid, N, M, x, y - 1);
            if (y < M - 1 && grid[x][y + 1] == '1')
                flood(grid, N, M, x, y + 1);
        }
    };
}