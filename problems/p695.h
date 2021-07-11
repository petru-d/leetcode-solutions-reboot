#pragma once
#include <vector>

namespace p695
{
    class Solution
    {
      public:
        int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
        {
            auto R = grid.size();
            auto C = grid.front().size();

            int max_area = 0;
            for (size_t i = 0; i < R; ++i)
                for (size_t j = 0; j < C; ++j)
                    if (grid[i][j] == 1)
                    {
                        int curr_area = 0;
                        get_area(R, C, grid, i, j, curr_area);
                        max_area = std::max(max_area, curr_area);
                    }

            return max_area;
        }

      private:
        void get_area(size_t R, size_t C, std::vector<std::vector<int>>& grid, size_t i, size_t j, int& area)
        {
            ++area;
            grid[i][j] = 2;

            if (i < R - 1 && grid[i + 1][j] == 1)
                get_area(R, C, grid, i + 1, j, area);
            if (j < C - 1 && grid[i][j + 1] == 1)
                get_area(R, C, grid, i, j + 1, area);
            if (i > 0 && grid[i - 1][j] == 1)
                get_area(R, C, grid, i - 1, j, area);
            if (j > 0 && grid[i][j - 1] == 1)
                get_area(R, C, grid, i, j - 1, area);
        }
    };
}
