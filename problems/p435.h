#pragma once
#include <algorithm>
#include <map>
#include <set>
#include <vector>

namespace p435
{
    class Solution
    {
      public:
        int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
        {
            // Sort by end.
            std::sort(intervals.begin(), intervals.end(), [](const auto x, const auto y) { return x[1] < y[1]; });

            // The invariant: the current selected intervals are optimal. If we encounter an interval which overlaps with anything
            // in our current solution, we elliminate it: it makes no sense to elliminate anything else, since those end earlier,
            // so they are less prone to kill other stuff that comes later.

            // keep the end of the last selected interval.
            int r = std::numeric_limits<int>::min();
            int result = 0;
            for (const auto& x : intervals)
                x[0] >= r ? r = x[1] : ++result;

            return result;
        }
    };
}
