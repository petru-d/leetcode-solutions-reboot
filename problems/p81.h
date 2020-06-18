#pragma once

#include <algorithm>
#include <vector>

namespace p81
{
    class Solution
    {
      public:
        // Points to the end of the first increasing range in a rotated sorted array.
        template <typename It> It find_cusp(It l, It r)
        {
            while (l != r && std::next(l) != r)
            {
                auto mid = l;
                std::advance(mid, std::distance(l, r) / 2);

                if (*l <= *mid)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }

            return r;
        }

        bool search(std::vector<int>& nums, int target)
        {
            if (nums.empty())
                return false;

            auto begin = nums.begin();
            auto end = nums.end();

            if (nums.front() == nums.back())
            {
                if (target == nums.front())
                    return true;

                auto f = nums.front();

                begin = std::find_if(nums.begin(), nums.end(), [f](int i) { return i != f; });
                end = std::find(begin, nums.end(), f);
            }

            auto it_cusp = find_cusp(begin, end);

            auto pos = std::lower_bound(begin, it_cusp, target);
            if (pos != it_cusp && *pos == target)
                return true;

            pos = std::lower_bound(it_cusp, end, target);
            return pos != end && *pos == target;
        }
    };
}
