#pragma once
#include <algorithm>
#include <vector>

namespace p55
{
    class Solution
    {
      public:
        bool canJump(std::vector<int>& nums)
        {
            if (nums.size() <= 1)
                return true;

            size_t reach = 0;
            size_t N = nums.size();
            for (size_t i = 0; i < N; ++i)
            {
                if (i > reach)
                    return false;
                reach = std::max(reach, i + nums[i]);
                if (reach >= N - 1)
                    return true;
            }

            return false;
        }
    };
}