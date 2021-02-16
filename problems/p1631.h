#pragma once
#include <vector>
#include <queue>
#include <array>

namespace p1631
{
    // Djikstra style
    class Solution
    {
      public:
        int minimumEffortPath(std::vector<std::vector<int>>& heights)
        {
            size_t R = heights.size();
            size_t C = heights.front().size();

            std::array<int, 5> d = {-1, 0, 1, 0, -1};

            std::vector<std::vector<int>> eff(R, std::vector<int>(C, std::numeric_limits<int>::max()));

            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

            auto encode = [](int x, int y) { return 100 * x + y; };

            auto decode = [](int code) { return std::pair<int, int>(code / 100, code % 100); };

            eff[0][0] = 0;
            q.emplace(0, encode(0, 0));
            while (!q.empty())
            {
                auto effort = q.top().first;
                auto [x, y] = decode(q.top().second);

                if (x == R - 1 && y == C - 1)
                    break;

                q.pop();

                for (auto i = 0; i < 4; ++i)
                {
                    auto nx = x + d[i];
                    auto ny = y + d[i + 1];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;
                    int n_effort = std::max(eff[x][y], std::abs(heights[x][y] - heights[nx][ny]));
                    if (n_effort < eff[nx][ny])
                    {
                        eff[nx][ny] = n_effort;
                        q.emplace(n_effort, encode(nx, ny));
                    }
                }
            }

            return eff[R - 1][C - 1];
        }
    };
}
