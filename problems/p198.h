#pragma once
#include <algorithm>
#include <vector>

namespace p198
{
    class Solution
    {
      public:
        int rob(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N == 0)
                return 0;

            std::vector<int> money(N, 0);
            money[0] = nums[0];
            if (N >= 2)
                money[1] = std::max(nums[1], nums[0]);

            for (size_t i = 2; i < N; ++i)
                money[i] = std::max(money[i - 1], nums[i] + money[i - 2]);

            return money.back();
        }
    };
}
