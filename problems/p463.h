#pragma once

#include <vector>

namespace p463
{
    class Solution
    {
      public:
        int islandPerimeter(std::vector<std::vector<int>>& grid)
        {
            if (grid.empty() || grid.front().empty())
                return 0;

            R = grid.size();
            C = grid.front().size();

            int p = 0;

            for (size_t i = 0; i < R; ++i)
                for (size_t j = 0; j < C; ++j)
                    if (grid[i][j] == 1)
                    {
                        measure(grid, i, j, p);
                        return p;
                    }

            return p;
        }

      private:
        void measure(std::vector<std::vector<int>>& grid, size_t i, size_t j, int& p)
        {
            grid[i][j] = 2;

            if (i == 0 || grid[i - 1][j] == 0)
                ++p;
            else if (grid[i - 1][j] == 1)
                measure(grid, i - 1, j, p);

            if (i == R - 1 || grid[i + 1][j] == 0)
                ++p;
            else if (grid[i + 1][j] == 1)
                measure(grid, i + 1, j, p);

            if (j == 0 || grid[i][j - 1] == 0)
                ++p;
            else if (grid[i][j - 1] == 1)
                measure(grid, i, j - 1, p);

            if (j == C - 1 || grid[i][j + 1] == 0)
                ++p;
            else if (grid[i][j + 1] == 1)
                measure(grid, i, j + 1, p);
        }

        size_t R = -1;
        size_t C = -1;
    };
}
