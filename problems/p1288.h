#pragma once
#include <vector>

namespace p1288
{
    class Solution
    {
      public:
        int removeCoveredIntervals(std::vector<std::vector<int>>& intervals)
        {
            size_t N = intervals.size();
            if (N <= 1)
                return int(N);

            std::sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) {
                if (l[0] < r[0])
                    return true;
                if (l[0] == r[0])
                    return l[1] > r[1];
                return false;
            });

            int result = int(N);
            auto& curr = intervals[0];
            for (size_t i = 1; i < N; ++i)
            {
                if (intervals[i][1] <= curr[1])
                    --result;
                else
                    curr = intervals[i];
            }

            return result;
        }
    };
}
