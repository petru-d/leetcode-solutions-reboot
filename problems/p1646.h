#pragma once
#include <array>
#include <algorithm>

namespace p1646
{
    class Solution
    {
      public:
        int getMaximumGenerated(int n)
        {
            if (n == 0)
                return 0;

            std::array<int, 101> arr = {};
            arr[1] = 1;

            int res = 1;
            for (size_t i = 2; i <= size_t(n); ++i)
            {
                auto [q, r] = std::div(int(i), 2);
                if (r == 0)
                    arr[i] = arr[q];
                else
                    arr[i] = arr[q] + arr[q + size_t(1)];

                res = std::max(res, arr[i]);
            }

            return res;
        }
    };
}
