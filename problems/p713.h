#pragma once
#include <vector>

namespace p713
{
    class Solution
    {
      public:
        int numSubarrayProductLessThanK(std::vector<int>& nums, int k)
        {
            size_t N = nums.size();
            if (N == 0 || k <= 1)
                return 0;

            int current_prod = 1;
            size_t left = 0;
            int res = 0;
            for (size_t right = 1; right <= N; ++right)
            {
                current_prod *= nums[right - 1];
                while (current_prod >= k && left < right)
                    current_prod /= nums[left++];
                res += int(right - left);
            }

            return res;
        }
    };
}
