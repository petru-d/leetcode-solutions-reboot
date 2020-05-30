#pragma once
#include <algorithm>
#include <vector>

namespace p931
{
    class Solution
    {
      public:
        int minFallingPathSum(std::vector<std::vector<int>>& A)
        {
            size_t AA = A.size();

            std::vector<int> prev_row = A[0];
            std::vector<int> curr_row = A[0];

            for (size_t i = 1; i < AA; ++i)
            {
                for (size_t j = 0; j < AA; ++j)
                {
                    int north_west = j > 0 ? prev_row[j - 1] : std::numeric_limits<int>::max();
                    int north = prev_row[j];
                    int north_east = j < AA - 1 ? prev_row[j + 1] : std::numeric_limits<int>::max();
                    curr_row[j] = A[i][j] + std::min({north_east, north, north_west});
                }

                std::swap(prev_row, curr_row);
            }

            return *std::min_element(prev_row.begin(), prev_row.end());
        }
    };
}