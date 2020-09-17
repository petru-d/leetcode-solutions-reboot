#pragma once
#include <algorithm>
#include <vector>

namespace p57
{
    class Solution
    {
      public:
        using IntervalT = std::vector<int>;
        std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
        {
            auto [low, hi] = std::equal_range(intervals.begin(), intervals.end(), newInterval,
                                              [](const IntervalT& l, const IntervalT& r) { return l[1] < r[0]; });

            if (low == hi)
            {
                if (low == intervals.end())
                {
                    intervals.push_back(newInterval);
                    return std::move(intervals);
                }

                if (overlaps(*low, newInterval))
                {
                    *low = merge(*low, newInterval);
                    return std::move(intervals);
                }

                intervals.insert(low, newInterval);
                return std::move(intervals);
            }

            *low = merge(merge(*low, newInterval), *std::prev(hi));

            intervals.erase(std::next(low), hi);
            return std::move(intervals);
        }

      private:
        bool overlaps(const IntervalT& l, const IntervalT& r)
        {
            if (l[1] < r[0])
                return false;
            if (r[1] < l[0])
                return false;
            return true;
        }

        IntervalT merge(const IntervalT& l, const IntervalT& r)
        {
            return {std::min(l[0], r[0]), std::max(l[1], r[1])};
        }
    };
}
