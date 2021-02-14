#pragma once
#include <vector>

namespace p1658
{
    class Solution
    {
      public:
        int minOperations(std::vector<int>& nums, int x)
        {
            // nums = {1, 2, 3}
            // sums_left = {0, 1, 3, 6}
            // sums_right = {0, 3, 5, 6}
            // // sums_right = {6, 5, 3, 0}
            auto N = nums.size();
            std::vector<int> sums_left(N + 1, 0);
            std::vector<int> sums_right(N + 1, 0);

            for (size_t i = 0; i < N; ++i)
            {
                sums_left[i + 1] = sums_left[i] + nums[i];
                sums_right[i + 1] = sums_right[i] + nums[N - i - 1];
                // sums_right[N - i - 1] = sums_left[N - i] + nums[N - i - 1];
            }
            int best = std::numeric_limits<int>::max();
            for (size_t i = 0; i < N + 1; ++i)
            {
                if (sums_left[i] > x || int(i) >= best)
                    break;

                auto pos = std::lower_bound(sums_right.begin(), sums_right.end(), x - sums_left[i]);
                auto dist = std::distance(sums_right.begin(), pos);
                if (pos != sums_right.end() && *pos == x - sums_left[i] && i + dist <= N)
                    best = std::min(best, int(i + dist));
            }

            return best == std::numeric_limits<int>::max() ? -1 : best;
        }
    };
}
