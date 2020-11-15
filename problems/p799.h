#pragma once

#include <algorithm>
#include <vector>

namespace p799
{
    class Solution
    {
      public:
        double champagneTower(int poured, int query_row, int query_glass)
        {
            std::vector<std::vector<double>> cups(size_t(query_row) + 1, std::vector<double>(size_t(query_row) + 1, 0));

            cups[0][0] = poured;

            // update row by row
            for (size_t i = 1; i <= query_row; ++i)
            {
                for (size_t j = 0; j <= i; ++j)
                {
                    if (j == 0)
                    {
                        if (cups[i - 1][j] > 1)
                            cups[i][j] += (cups[i - 1][j] - 1) / 2;
                    }
                    else if (j == i)
                    {
                        if (cups[i - 1][j - 1] > 1)
                            cups[i][j] += (cups[i - 1][j - 1] - 1) / 2;
                    }
                    else
                    {
                        if (cups[i - 1][j] > 1)
                            cups[i][j] += (cups[i - 1][j] - 1) / 2;
                        if (cups[i - 1][j - 1] > 1)
                            cups[i][j] += (cups[i - 1][j - 1] - 1) / 2;
                    }
                };

                for (size_t j = 0; j <= i - 1; ++j)
                    cups[i - 1][j] = std::min(double(1), cups[i - 1][j]);
            }

            for (size_t j = 0; j <= query_row; ++j)
                cups[query_row][j] = std::min(double(1), cups[query_row][j]);

            return cups[query_row][query_glass];
        }
    };
}
