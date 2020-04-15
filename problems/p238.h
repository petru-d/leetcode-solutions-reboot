#pragma once
#include <cassert>
#include <vector>

namespace p238
{
    class Solution
    {
      public:
        std::vector<int> productExceptSelf(std::vector<int>& nums)
        {
            auto N = nums.size();

            std::vector<int> result(N, 1);

            // go forward - write in the output partial products
            for (size_t i = 1; i < N; ++i)
                result[i] = result[i - 1] * nums[i - 1];

            // go backward - multiply the partial products with current backward product
            int curr_back = nums[N - 1];
            for (int i = N - 2; i >= 0; --i)
            {
                result[i] *= curr_back;
                curr_back *= nums[i];
            }

            return result;
        }
    };
}