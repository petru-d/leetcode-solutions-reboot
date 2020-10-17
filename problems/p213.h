#pragma once
#include <vector>

namespace p213
{
    class Solution
    {
      public:
        int rob(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N == 0)
                return 0;
            if (N == 1)
                return nums[0];

            return std::max(rob_flat(nums, 1, N), rob_flat(nums, 0, N - 1));
        }

      private:
        int rob_flat(const std::vector<int>& houses, size_t start, size_t end)
        {
            if (end - start == 1)
                return houses[start];

            int prev_prev = houses[start];
            int prev = std::max(houses[start + 1], houses[start]);

            int curr = prev;

            for (size_t i = start + 2; i < end; ++i)
            {
                curr = std::max(houses[i] + prev_prev, prev);

                prev_prev = prev;
                prev = curr;
            }

            return curr;
        }
    };
}
