#pragma once
#include <algorithm>
#include <vector>

namespace p421
{
    class Solution
    {
      public:
        int findMaximumXOR(std::vector<int>& nums)
        {
            for (int b = 30; b >= 0; --b)
            {
                auto pp = std::partition(nums.begin(), nums.end(), [b](int n) { return n & (1UL << b); });
                if (pp != nums.begin() && pp != nums.end())
                    return (1UL << b) | compare_ranges({nums.begin(), pp}, {pp, nums.end()}, b - 1);
            }
            return 0;
        }

      private:
        struct Range
        {
            std::vector<int>::iterator begin;
            std::vector<int>::iterator end;
            bool empty() const
            {
                return begin == end;
            }
        };
        int compare_ranges(Range first, Range second, int b)
        {
            if (b < 0)
                return 0;

            auto pp1 = std::partition(first.begin, first.end, [b](int n) { return n & (1UL << b); });
            auto pp2 = std::partition(second.begin, second.end, [b](int n) { return n & (1UL << b); });

            Range first_ones = {first.begin, pp1};
            Range first_zeros = {pp1, first.end};

            Range second_ones = {second.begin, pp2};
            Range second_zeros = {pp2, second.end};

            auto xor1 = (!first_ones.empty() && !second_zeros.empty());
            auto xor2 = (!first_zeros.empty() && !second_ones.empty());

            if (xor1 || xor2)
            {
                if (b == 0)
                    return 1;

                int res1 = xor1 ? compare_ranges(first_ones, second_zeros, b - 1) : -1;
                int res2 = xor2 ? compare_ranges(first_zeros, second_ones, b - 1) : -1;

                return (1UL << b) | std::max(res1, res2);
            }
            return compare_ranges(first, second, b - 1);
        }
    };
}