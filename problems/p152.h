#pragma once

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace p152
{
    class Solution
    {
      public:
        int maxProduct(std::vector<int>& nums)
        {
            int maxi = std::numeric_limits<int>::min();

            auto curr = nums.begin();
            while (curr != nums.end() && *curr == 0)
            {
                maxi = std::max(maxi, 0);
                ++curr;
            }

            while (curr != nums.end())
            {
                auto next_curr = std::find(curr, nums.end(), 0);

                maxi = std::max(maxi, maxProductNonZero(nums, curr, next_curr));
                if (next_curr != nums.end())
                    maxi = std::max(maxi, 0);

                while (next_curr != nums.end() && *next_curr == 0)
                    ++next_curr;

                curr = next_curr;
            }

            return maxi;
        }

        int maxProductNonZero(const std::vector<int>& nums, std::vector<int>::const_iterator start,
                              std::vector<int>::const_iterator end)
        {
            assert(start != end && start != nums.end());

            if (std::next(start) == end)
                return *start;

            int all_prod = std::accumulate(start, end, 1, std::multiplies());
            if (all_prod > 0)
                return all_prod;

            int maxi = all_prod;

            int curr_left_prod = 1;
            for (auto it = start; it < end; ++it)
            {
                if (*it < 0)
                    maxi = std::max({maxi, curr_left_prod, all_prod / (curr_left_prod * *it)});

                curr_left_prod *= *it;
            }

            return maxi;
        }
    };
}
