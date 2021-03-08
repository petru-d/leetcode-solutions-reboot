#pragma once
#include <numeric>
#include <vector>

namespace p268
{
    class Solution
    {
      public:
        int missingNumber1(std::vector<int>& nums)
        {
            int sum = std::accumulate(nums.begin(), nums.end(), 0);

            return nums.size() * (nums.size() + 1) / 2 - sum;
        }
        int missingNumber2(std::vector<int>& nums)
        {
            nums.push_back(-1);
            auto N = nums.size();
            for (size_t i = 0; i < N; ++i)
            {
                while (nums[i] != -1 && nums[i] != i)
                    std::swap(nums[i], nums[nums[i]]);
            }

            for (size_t i = 0; i < N; ++i)
                if (nums[i] == -1)
                    return i;

            return -1;
        }
    };
}
