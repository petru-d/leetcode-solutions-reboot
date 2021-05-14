#pragma once
#include <vector>

namespace p665
{
    class Solution
    {
      public:
        bool checkPossibility(std::vector<int>& nums)
        {
            auto N = nums.size();
            if (N <= 2)
                return true;

            int fixCount = 0;
            int prev_prev = std::numeric_limits<int>::min();
            int prev = nums[0];

            if (nums[0] > nums[1])
            {
                ++fixCount;
                prev = prev_prev;
            }

            for (size_t i = 1; i < N; ++i)
            {
                // check range [prev_prev, prev, nums[i]]
                // we know that prev_prev <= prev

                // no fix needed
                if (nums[i] >= prev)
                {
                    prev_prev = prev;
                    prev = nums[i];
                    continue;
                }

                ++fixCount;
                if (fixCount >= 2)
                    return false;

                // we need to fix the range ending at nums[i]

                // the best fix is to decrease nums[i - 1] to nums[i], but this is possible only if
                if (nums[i] >= prev_prev)
                {
                    // -1 4 2 -> -1 2 2
                    prev_prev = prev = nums[i];
                }
                else
                {
                    // the best fix is not possible - need to raise nums[i] to prev
                    // 5 7 1 -> 5 7 7
                    prev_prev = prev;
                    // prev stays the same
                }
            }

            return true;
        }
    };
}
