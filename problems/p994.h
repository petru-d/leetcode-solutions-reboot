#pragma once
#include <cassert>
#include <vector>

namespace p994
{
    class Solution
    {
      public:
        int orangesRotting(std::vector<std::vector<int>>& grid)
        {
            size_t R = grid.size();
            size_t C = grid.front().size();

            if (R == 0 || C == 0)
                return 0;

            auto next_grid = grid;

            int steps = 0;
            while (true)
            {
                bool found_non_rotten = false;
                bool advanced = false;
                for (size_t i = 0; i < R; ++i)
                    for (size_t j = 0; j < C; ++j)
                    {
                        next_grid[i][j] = grid[i][j];
                        if (grid[i][j] == 1)
                        {
                            found_non_rotten = true;

                            bool west_rot = j > 0 && grid[i][j - 1] == 2;
                            bool east_rot = j < C - 1 && grid[i][j + 1] == 2;
                            bool south_rot = i < R - 1 && grid[i + 1][j] == 2;
                            bool north_rot = i > 0 && grid[i - 1][j] == 2;
                            if (east_rot || west_rot || south_rot || north_rot)
                            {
                                next_grid[i][j] = 2;
                                advanced = true;
                            }
                        }
                    }

                if (!advanced)
                    return found_non_rotten ? -1 : steps;
                ++steps;
                std::swap(grid, next_grid);
            }

            assert(false);
            return -1;
        }
    };
}
