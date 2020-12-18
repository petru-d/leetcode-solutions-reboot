#pragma once
#include <vector>
#include <string>

namespace p163
{
    class Solution
    {
      public:
        std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper)
        {
            std::vector<std::string> res;
            auto add_range = [&res](int l, int r) {
                if (l == r)
                    return;

                if (l + 1 == r)
                {
                    res.push_back(std::to_string(l));
                    return;
                }

                std::string range_str = std::to_string(l);
                range_str += "->";
                range_str += std::to_string(r - 1);

                res.push_back(std::move(range_str));
            };

            if (nums.empty())
            {
                add_range(lower, upper + 1);
                return res;
            }

            auto start = lower;
            for (const auto n : nums)
            {
                add_range(start, n);
                start = n + 1;
            }
            add_range(nums.back() + 1, upper + 1);

            return res;
        }
    };
}
