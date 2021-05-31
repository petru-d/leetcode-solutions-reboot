#pragma once
#include <array>
#include <vector>

namespace p1695
{
    class Solution
    {
      public:
        int maximumUniqueSubarray(std::vector<int>& nums)
        {
            std::array<uint16_t, 10000> present = {};

            auto curr_sum = nums[0];
            auto best_sum = nums[0];
            present[nums[0] - 1] = 1;
            size_t left = 0;
            auto N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                while (left < i && present[nums[i] - 1])
                {
                    --present[nums[left] - 1];
                    curr_sum -= nums[left];
                    ++left;
                }
                curr_sum += nums[i];
                ++present[nums[i] - 1];

                best_sum = std::max(best_sum, curr_sum);
            }

            return best_sum;
        }
    };
}
