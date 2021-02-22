#pragma once

#include <bitset>
#include <vector>
#include <cmath>

namespace p78
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums)
        {
            std::vector<std::vector<int>> pset;

            size_t p = static_cast<size_t>(pow(2, nums.size()));

            for (size_t i = 0; i < p; ++i)
            {
                std::bitset<32> bits(i);

                std::vector<int> subset;
                for (size_t b = 0; b < nums.size(); ++b)
                    if (bits[b])
                        subset.push_back(nums[b]);

                pset.emplace_back(std::move(subset));
            }

            return pset;
        }
    };
}
