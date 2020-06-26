#pragma once
#include <vector>

namespace p287
{
    class Solution
    {
      public:
        int findDuplicate(std::vector<int>& nums)
        {
            int low = 1;
            int hi = int(nums.size()) - 1;

            while (low < hi)
            {
                int pivot = (low + hi) / 2;

                size_t less_pivot = 0;
                size_t eq_pivot = 0;
                size_t more_pivot = 0;
                for (auto n : nums)
                {
                    if (n < pivot)
                        ++less_pivot;
                    if (n == pivot)
                        ++eq_pivot;
                    if (n > pivot)
                        ++more_pivot;
                }

                if (eq_pivot > 1)
                    return pivot;

                if (less_pivot >= pivot)
                    hi = pivot - 1;
                else
                    low = pivot + 1;
            }

            return hi;
        }
    };
}
