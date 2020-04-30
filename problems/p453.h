#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

namespace p453
{

    class Solution
    {
      public:
        int minMoves_(std::vector<int>& nums)
        {
            size_t N = nums.size();

            std::sort(nums.rbegin(), nums.rend());

            int result = 0;

            int mul = 1;
            for (size_t i = 0; i < N - 1; ++i)
            {
                int delta = nums[i] - nums[i + 1];

                result += delta * mul;
                ++mul;
            }

            return result;
        }

        // Increasing the smallest n-1 elements by 1 has the same effect on the "delta sum" as decreasing the biggest element
        // by 1.
        // "delta sum" is the sum of a[i] - a[i-1] (for i = 1 to N-1), in the sorted array.
        int minMoves(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N == 0)
                return 0;

            auto min = nums[0];
            size_t sum = nums[0];
            for (size_t i = 1; i < N; ++i)
            {
                min = std::min(min, nums[i]);
                sum += nums[i];
            }

            return static_cast<int>(sum - (nums.size()) * min);
        }
    };
}