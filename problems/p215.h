#pragma once

#include <algorithm>
#include <vector>

namespace p215
{
    class Solution
    {
      public:
        int findKthLargest(std::vector<int>& nums, int k)
        {
            size_t K = size_t(k);
            size_t N = nums.size();

            std::vector<int> first_k;
            first_k.reserve(K);

            for (size_t i = 0; i < K; ++i)
            {
                first_k.push_back(nums[i]);
            }

            auto lass = [](int l, int r) { return l > r; };

            std::make_heap(first_k.begin(), first_k.end(), lass);

            for (size_t i = K; i < N; ++i)
            {
                if (nums[i] <= first_k.front())
                    continue;

                std::pop_heap(first_k.begin(), first_k.end(), lass);
                first_k.back() = nums[i];
                std::push_heap(first_k.begin(), first_k.end(), lass);
            }

            return first_k.front();
        }
    };

}