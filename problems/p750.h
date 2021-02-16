#pragma once
#include <vector>

namespace p750
{
    class Solution
    {
      public:
        int countCornerRectangles(std::vector<std::vector<int>>& grid)
        {
            auto R = grid.size();
            auto C = grid.front().size();

            std::vector<std::vector<size_t>> col_ones(C, std::vector<size_t>{});

            for (size_t i = 0; i < C; ++i)
                for (size_t j = 0; j < R; ++j)
                {
                    if (grid[j][i] == 1)
                        col_ones[i].push_back(j);
                }

            int res = 0;
            for (size_t f = 0; f < C; ++f)
                for (size_t s = f + 1; s < C; ++s)
                {
                    int eq_points = get_eq_points(col_ones[f], col_ones[s]);
                    if (eq_points >= 2)
                        res += eq_points * (eq_points - 1) / 2;
                }

            return res;
        }

        int get_eq_points(const std::vector<size_t>& f, const std::vector<size_t>& s)
        {
            int eq_points = 0;
            size_t pos_f = 0;
            size_t pos_s = 0;
            while (pos_f < f.size() && pos_s < s.size())
            {
                if (f[pos_f] == s[pos_s])
                {
                    ++pos_s;
                    ++eq_points;
                }
                else if (f[pos_f] < s[pos_s])
                {
                    ++pos_f;
                }
                else
                {
                    ++pos_s;
                }
            }

            return eq_points;
        }
    };
}
