#pragma once
#include <limits>
#include <set>
#include <stack>
#include <vector>

namespace p694
{
    struct Island
    {
        // invariant here - should be a class
        std::set<std::pair<size_t, size_t>> Points;
        size_t Top = std::numeric_limits<size_t>::max();
        size_t Left = std::numeric_limits<size_t>::max();

        void Add(size_t x, size_t y)
        {
            Points.insert({x, y});
            Top = std::min(Top, y);
            Left = std::min(Left, x);
        }
        void Normalize()
        {
            std::set<std::pair<size_t, size_t>> normalPoints;
            for (auto& p : Points)
                normalPoints.insert({p.first - Left, p.second - Top});
            Points = std::move(normalPoints);
        }
    };
    bool operator<(const Island& left, const Island& right)
    {
        if (left.Points.size() != right.Points.size())
            return left.Points.size() < right.Points.size();

        auto li = left.Points.begin();
        auto ri = right.Points.begin();
        for (; li != left.Points.end(); ++li, ++ri)
        {
            if (*li != *ri)
                return *li < *ri;
        }
        return false;
    };

    class Solution
    {
      public:
        int numDistinctIslands(std::vector<std::vector<int>>& grid)
        {

            auto make_island = [&](size_t x, size_t y) {
                Island island;

                std::stack<std::pair<size_t, size_t>> explore;
                explore.push({x, y});
                while (!explore.empty())
                {
                    auto [x, y] = explore.top();
                    island.Add(x, y);
                    grid[x][y] = 2;
                    explore.pop();

                    if (x > 0 && grid[x - 1][y] == 1)
                        explore.push({x - 1, y});
                    if (x < grid.size() - 1 && grid[x + 1][y] == 1)
                        explore.push({x + 1, y});
                    if (y > 0 && grid[x][y - 1] == 1)
                        explore.push({x, y - 1});
                    if (y < grid.front().size() - 1 && grid[x][y + 1] == 1)
                        explore.push({x, y + 1});
                }
                island.Normalize();
                return island;
            };

            std::set<Island> isls;

            for (size_t i = 0; i < grid.size(); ++i)
                for (size_t j = 0; j < grid.front().size(); ++j)
                    if (grid[i][j] == 1)
                        isls.insert(make_island(i, j));

            return isls.size();
        }
    };
}
