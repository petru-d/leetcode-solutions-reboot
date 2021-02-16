#pragma once
#include <vector>
#include <algorithm>

namespace p1329
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat)
        {
            size_t L = mat.size();
            size_t C = mat.front().size();

            auto sd = [&](size_t x, size_t y) {
                auto oldx = x;
                auto oldy = y;
                std::vector<int> v;
                v.reserve(std::max(L, C));
                while (x < L && y < C)
                {
                    v.push_back(mat[x][y]);
                    ++x;
                    ++y;
                }

                std::sort(v.begin(), v.end());

                auto V = v.size();
                for (size_t i = 0; i < V; ++i)
                {
                    mat[oldx][oldy] = v[i];
                    ++oldx;
                    ++oldy;
                }
            };

            for (size_t i = 0; i < C; ++i)
                sd(0, i);

            for (size_t i = 1; i < L; ++i)
                sd(i, 0);

            return std::move(mat);
        }
    };
}
