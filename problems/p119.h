#pragma once
#include <vector>

namespace p119
{
    class Solution
    {
      public:
        std::vector<int> getRow(int rowIndex)
        {
            std::vector<int> prev_row(size_t(rowIndex) + 1, 1);
            std::vector<int> curr_row = prev_row;

            for (size_t i = 1; i <= size_t(rowIndex); ++i)
            {
                for (size_t j = 1; j < i; ++j)
                    curr_row[j] = prev_row[j - 1] + prev_row[j];

                std::swap(curr_row, prev_row);
            }

            return prev_row;
        }
    };
}
