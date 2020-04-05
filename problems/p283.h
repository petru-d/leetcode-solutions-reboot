#pragma once
#include <vector>

namespace p283
{
    class Solution
    {
      public:
        void moveZeroes(std::vector<int>& nums)
        {
            size_t zero_count = 0;
            size_t N = nums.size();
            for (size_t i = 0; i < N; ++i)
                if (nums[i] == 0)
                    ++zero_count;
                else
                    nums[i - zero_count] = nums[i];

            std::fill(nums.begin() + N - zero_count, nums.end(), 0);
        }
    };
}