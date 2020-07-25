#pragma once
#include <vector>

namespace p154
{
    class Solution
    {
      public:
        int findMin(std::vector<int>& nums)
        {
            size_t N = nums.size();
            size_t low = 0;

            while (low < N - 1 && nums[low] == nums[N - 1])
                ++low;

            if (low == N - 1 || nums[low] <= nums[N - 1])
                return nums[low];

            size_t z = low;
            for (size_t k = N; k >= 1; k /= 2)
                while (k + z < N && nums[k + z] >= nums[low])
                    z += k;

            return nums[z + 1];
        }
    };
}
