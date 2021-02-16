#pragma once
#include <vector>

namespace p1437
{
    class Solution
    {
      public:
        bool kLengthApart(std::vector<int>& nums, int k)
        {
            size_t N = nums.size();
            size_t last_one = -1;
            for (size_t i = 0; i < N; ++i)
            {
                if (nums[i] == 1)
                {
                    last_one = i;
                    break;
                }
            }

            if (last_one == -1)
                return true;

            for (size_t i = last_one + 1; i < N; ++i)
            {
                if (nums[i] == 1)
                {
                    if (i - last_one <= k)
                        return false;
                    last_one = i;
                }
            }
            return true;
        }
    };
}
