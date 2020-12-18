#pragma once
#include <vector>

namespace p416
{
    class Solution
    {
      public:
        bool canPartition(std::vector<int>& nums)
        {
            int total = 0;
            for (const auto n : nums)
                total += n;

            if (total % 2 == 1 || nums.size() <= 1)
                return false;

            size_t goal = size_t(total) / 2;
            size_t N = nums.size();

            bool memo[2][10000 + 1];

            memo[0][0] = true;
            for (size_t i = 1; i <= goal; ++i)
                memo[0][i] = (i == nums[0]);

            size_t prev = 0;
            size_t curr = 1;

            for (size_t k = 1; k < N; ++k)
            {
                for (size_t g = 1; g <= goal; ++g)
                {
                    memo[curr][g] = memo[prev][g];
                    if (g >= nums[k])
                        memo[curr][g] = memo[curr][g] || memo[prev][g - nums[k]];
                }
                std::swap(prev, curr);
            }

            return memo[prev][goal];
        }
    };
}
