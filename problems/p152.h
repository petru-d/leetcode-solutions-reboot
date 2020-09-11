#pragma once

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

/* solution from leetcode:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0], ma=nums[0], mi=nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]<0)
                swap(ma, mi);

            ma = max(ma*nums[i], nums[i]);
            mi = min(mi*nums[i], nums[i]);
            res = max(res, ma);
        }
        return res;
    }
};

// why it works:
  - when encountering zero, both max and min are reset to zero, so basically the algorithm works on non-zero sub-arrays
  - either ma or mi will contain the complete product of the current non-zero region.
    - ma will contain it if the current complete product is positive
    - mi will contain it if the current complete prduct is negative. during that time, ma will contain best positive product

  additional explanation:
    - it's dynamic programming, keeping at position i the max and min products of subarrays ending at i

 */

namespace p152
{
    class Solution
    {
      public:
        // can be a bit optimized by memorizing the total product of the non-zero areas while looking for zeros
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
