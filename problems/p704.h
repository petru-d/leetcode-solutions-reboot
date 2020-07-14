#pragma once

#include <vector>

namespace p704
{
    class Solution
    {
      public:
        int search(std::vector<int>& nums, int target)
        {
            auto pos = std::lower_bound(nums.begin(), nums.end(), target);

            return (pos != nums.end() && *pos == target) ? static_cast<int>(std::distance(nums.begin(), pos)) : -1;
        }
    };
}
