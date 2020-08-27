#pragma once
#include <cctype>
#include <unordered_map>
#include <vector>

namespace p1559
{
    class Solution
    {
      private:
        struct Point
        {
            size_t row = -1;
            size_t col = -1;
        };

        struct Corner
        {
            Point Foot1;
            Point Middle;
            Point Foot2;
        };

        void fill(std::vector<std::vector<char>>& grid, const Point& p, char from, char to)
        {
            if (p.row >= grid.size() || p.col >= grid.front().size() || grid[p.row][p.col] != from)
                return;

            grid[p.row][p.col] = to;
            fill(grid, {p.row - 1, p.col}, from, to);
            fill(grid, {p.row + 1, p.col}, from, to);
            fill(grid, {p.row, p.col - 1}, from, to);
            fill(grid, {p.row, p.col + 1}, from, to);
        }

        bool processCorner(const Corner& c, std::vector<std::vector<char>>& grid)
        {
            if (grid[c.Middle.row][c.Middle.col] <= 'Z' || grid[c.Middle.row][c.Middle.col] == '$')
                return false;

            char low = grid[c.Middle.row][c.Middle.col];

            grid[c.Middle.row][c.Middle.col] = std::toupper(low);

            fill(grid, c.Foot1, low, std::toupper(low));

            if (grid[c.Foot2.row][c.Foot2.col] == std::toupper(low))
                return true;

            fill(grid, c.Foot1, std::toupper(low), '$');
            fill(grid, c.Foot2, low, '$');
            return false;
        }

      public:
        bool containsCycle(std::vector<std::vector<char>>& grid)
        {
            if (grid.size() <= 1 || grid.front().size() <= 1)
                return false;

            size_t R = grid.size();
            size_t C = grid.front().size();

            std::vector<Corner> corners;

            for (size_t i = 0; i < R - 1; i++)
                for (size_t j = 0; j < C - 1; j++)
                {
                    std::unordered_map<char, std::vector<Point>> window_chars;
                    window_chars[grid[i][j]].push_back({i, j});
                    window_chars[grid[i + 1][j]].push_back({i + 1, j});
                    window_chars[grid[i][j + 1]].push_back({i, j + 1});
                    window_chars[grid[i + 1][j + 1]].push_back({i + 1, j + 1});

                    if (window_chars.size() == 1)
                        return true;

                    if (window_chars.size() == 2)
                    {
                        if (window_chars[grid[i][j]].size() == 1)
                            corners.push_back({{i + 1, j}, {i + 1, j + 1}, {i, j + 1}});
                        if (window_chars[grid[i + 1][j]].size() == 1)
                            corners.push_back({{i, j}, {i, j + 1}, {i + 1, j + 1}});
                        if (window_chars[grid[i][j + 1]].size() == 1)
                            corners.push_back({{i, j}, {i + 1, j}, {i + 1, j + 1}});
                        if (window_chars[grid[i + 1][j + 1]].size() == 1)
                            corners.push_back({{i, j + 1}, {i, j}, {i + 1, j}});
                    }
                }

            if (corners.size() == 0)
                return false;

            // remove corner middle, fill from one foot, see if we reach the other foot
            for (const auto& c : corners)
            {
                if (processCorner(c, grid))
                    return true;
            }

            return false;
        }
    };
}
