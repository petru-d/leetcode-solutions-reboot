#pragma once
#include <vector>

namespace p1351
{
    class Solution
    {
      public:
        int countNegativesBS(std::vector<std::vector<int>>& grid)
        {
            if (grid.empty())
                return 0;

            size_t total_negatives = 0;

            size_t cols = grid[0].size();
            size_t curr_neg_start = cols;
            for (size_t r = 0; r < grid.size(); ++r)
            {
                auto curr_neg_start_it =
                    std::upper_bound(grid[r].begin(), grid[r].begin() + curr_neg_start, 0, std::greater<int>());
                total_negatives += std::distance(curr_neg_start_it, grid[r].end());

                curr_neg_start = std::distance(grid[r].begin(), curr_neg_start_it);
            }

            return static_cast<int>(total_negatives);
        }

        int countNegatives(std::vector<std::vector<int>>& grid)
        {
            if (grid.empty())
                return 0;

            size_t R = grid.size();
            size_t C = grid.front().size();

            int total_neg = 0;

            size_t curr_col = C;

            for (size_t r = 0; r < R; ++r)
            {
                while (curr_col >= 1 && grid[r][curr_col - 1] < 0)
                    --curr_col;
                if (curr_col == 0)
                    return static_cast<int>(total_neg + (R - r) * C);

                total_neg += static_cast<int>(C - curr_col);
            }

            return total_neg;
        }
    };
}
