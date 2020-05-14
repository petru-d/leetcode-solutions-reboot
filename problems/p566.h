#pragma once
#include <vector>

namespace p566
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c)
        {
            size_t orig_r = nums.size();
            size_t orig_c = nums.front().size();

            if (r * size_t(c) != orig_c * orig_r)
                return std::move(nums);

            std::vector<std::vector<int>> result(r, std::vector<int>(c, 0));

            for (size_t i = 0; i < orig_r * orig_c; ++i)
            {
                auto [new_r, new_c] = lldiv(i, c);
                auto [old_r, old_c] = lldiv(i, orig_c);
                result[new_r][new_c] = nums[old_r][old_c];
            }

            return result;
        }
    };
}