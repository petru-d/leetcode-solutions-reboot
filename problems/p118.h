#pragma once
#include <vector>

namespace p118
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> generate(int numRows)
        {
            std::vector<std::vector<int>> result;

            if (numRows == 0)
                return result;

            result.push_back({1});
            for (size_t i = 1; i < size_t(numRows); ++i)
            {
                std::vector<int> curr_row(i + 1, 1);

                for (size_t j = 1; j < i; ++j)
                {
                    const auto& prev_row = result.back();
                    curr_row[j] = prev_row[j - 1] + prev_row[j];
                }

                result.emplace_back(curr_row);
            }

            return result;
        }
    };
}
