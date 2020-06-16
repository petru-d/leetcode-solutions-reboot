#pragma once
#include <algorithm>
#include <vector>

namespace p120
{
    class Solution
    {
      public:
        int minimumTotal(std::vector<std::vector<int>>& triangle)
        {
            if (triangle.empty())
                return 0;

            std::vector<int> min_sum_prev(triangle.size(), 0);
            min_sum_prev[0] = triangle[0][0];
            std::vector<int> min_sum = min_sum_prev;

            for (size_t r = 1; r < triangle.size(); ++r)
            {
                min_sum[0] = triangle[r][0] + min_sum_prev[0];
                min_sum[r] = triangle[r][r] + min_sum_prev[r - 1];
                for (size_t c = 1; c < r; ++c)
                {
                    min_sum[c] = triangle[r][c] + std::min(min_sum_prev[c - 1], min_sum_prev[c]);
                }
                std::swap(min_sum, min_sum_prev);
            }

            return *std::min_element(min_sum_prev.begin(), min_sum_prev.end());
        }
    };
}
