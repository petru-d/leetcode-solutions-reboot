#pragma once
#include <queue>
#include <vector>

namespace p1091
{
    class Solution
    {
      public:
        int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid)
        {
            auto N = grid.size();
            if (grid[0][0] != 0 || grid[N - 1][N - 1] != 0)
                return -1;

            auto assign_grid = [&](size_t x, size_t y, int val) {
                if (x == -1 || x == N || y == -1 || y == N)
                    return false;
                if (grid[x][y] != 0)
                    return false;

                grid[x][y] = val;
                return true;
            };

            std::deque<std::pair<int, int>> q;
            q.push_back({0, 0});
            grid[0][0] = -1;
            while (!q.empty())
            {
                auto sz = q.size();
                for (int k = 0; k < sz; ++k)
                {
                    auto [x, y] = q.front();
                    int dist = grid[x][y];
                    q.pop_front();

                    if (x == N - 1 && y == N - 1)
                        return -grid[x][y];

                    for (int i = -1; i <= 1; ++i)
                        for (int j = -1; j <= 1; ++j)
                        {
                            auto new_x = x + i;
                            auto new_y = y + j;
                            if (new_x == x && new_y == y)
                                continue;
                            if (assign_grid(new_x, new_y, dist - 1))
                                q.push_back({new_x, new_y});
                        }
                }
            }

            return -1;
        }
    };
}
