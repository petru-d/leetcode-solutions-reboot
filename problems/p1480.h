#pragma once
#include <vector>

namespace p1480
{
    class Solution
    {
      public:
        std::vector<int> runningSum(std::vector<int>& nums)
        {
            auto N = nums.size();
            if (N == 0)
                return {};

            std::vector<int> result(N, 0);
            result[0] = nums[0];
            for (size_t i = 1; i < N; ++i)
            {
                result[i] = result[i - 1] + nums[i];
            }

            return result;
        }
    };
}
