#pragma once
#include <vector>

namespace p462
{
    class Solution
    {
      public:
        int minMoves2(std::vector<int>& nums)
        {
            std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
            int median = nums[nums.size() / 2];

            int result = 0;
            for (auto n : nums)
                result += std::abs(n - median);

            return result;
        }
    };
}
