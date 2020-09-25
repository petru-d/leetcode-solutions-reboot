#pragma once
#include <cassert>
#include <vector>

namespace p980
{
    class Solution
    {
      public:
        struct Point
        {
            size_t X = -1;
            size_t Y = -1;
        };
        using Grid = std::vector<std::vector<int>>;

        int uniquePathsIII(std::vector<std::vector<int>>& grid)
        {
            size_t N = grid.size();
            size_t M = grid.front().size();

            Point start;
            Point end;
            size_t zero_count = 0;
            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < M; ++j)
                {
                    if (grid[i][j] == 1)
                        start = {i, j};
                    if (grid[i][j] == 2)
                        end = {i, j};
                    zero_count += (grid[i][j] == 0);
                }

            return go(grid, start, zero_count);
        }

      private:
        bool left(const Grid& grid, const Point& p, int val)
        {
            return (p.Y > 0 && grid[p.X][p.Y - 1] == val);
        }
        Point left(const Point& p)
        {
            return {p.X, p.Y - 1};
        }
        bool right(const Grid& grid, const Point& p, int val)
        {
            return p.Y < grid.front().size() - 1 && grid[p.X][p.Y + 1] == val;
        }
        Point right(const Point& p)
        {
            return {p.X, p.Y + 1};
        }
        bool up(const Grid& grid, const Point& p, int val)
        {
            return p.X > 0 && grid[p.X - 1][p.Y] == val;
        }
        Point up(const Point& p)
        {
            return {p.X - 1, p.Y};
        }
        bool down(const Grid& grid, const Point& p, int val)
        {
            return p.X < grid.size() - 1 && grid[p.X + 1][p.Y] == val;
        }
        Point down(const Point& p)
        {
            return {p.X + 1, p.Y};
        }
        void set(Grid& grid, const Point& p, int val)
        {
            grid[p.X][p.Y] = val;
        }
        int go(std::vector<std::vector<int>>& grid, Point curr, size_t zero_count)
        {
            assert(grid[curr.X][curr.Y] == 1);

            if (left(grid, curr, 2) && zero_count == 0)
                return 1;
            if (right(grid, curr, 2) && zero_count == 0)
                return 1;
            if (up(grid, curr, 2) && zero_count == 0)
                return 1;
            if (down(grid, curr, 2) && zero_count == 0)
                return 1;

            if (zero_count == 0)
                return 0;

            int total_paths = 0;
            if (left(grid, curr, 0))
            {
                set(grid, left(curr), 1);
                total_paths += go(grid, left(curr), zero_count - 1);
                set(grid, left(curr), 0);
            }
            if (right(grid, curr, 0))
            {
                set(grid, right(curr), 1);
                total_paths += go(grid, right(curr), zero_count - 1);
                set(grid, right(curr), 0);
            }
            if (up(grid, curr, 0))
            {
                set(grid, up(curr), 1);
                total_paths += go(grid, up(curr), zero_count - 1);
                set(grid, up(curr), 0);
            }
            if (down(grid, curr, 0))
            {
                set(grid, down(curr), 1);
                total_paths += go(grid, down(curr), zero_count - 1);
                set(grid, down(curr), 0);
            }
            return total_paths;
        }
    };
}
