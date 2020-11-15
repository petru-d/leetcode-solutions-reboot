#pragma once
#include <vector>

namespace p1283
{
    class Solution
    {
      public:
        int smallestDivisor(std::vector<int>& nums, int threshold)
        {
            int low = 1;

            auto [high, sn] = getHighAndSum(nums);
            if (int64_t(threshold) >= sn)
                return 1;

            // find lowest number that brings us under or equal to threshold
            // divResult(nums, low) > threshold
            while (low + 1 < high)
            {
                auto mid = (low + high) / 2;

                auto res = divResult(nums, mid);

                if (res > threshold)
                    low = mid;
                else
                    high = mid;
            }

            return high;
        }

        std::pair<int, int64_t> getHighAndSum(const std::vector<int>& nums)
        {
            size_t N = nums.size();
            int high = nums[0];
            int64_t sum = nums[0];

            for (size_t i = 1; i < N; ++i)
            {
                high = std::max(high, nums[i]);
                sum += nums[i];
            }

            return {high, sum};
        }

        int divResult(const std::vector<int>& nums, int divisor)
        {
            int result = 0;
            for (const auto& n : nums)
            {
                auto [q, r] = std::div(n, divisor);
                result += q + (r != 0);
            }

            return result;
        }
    };
}
