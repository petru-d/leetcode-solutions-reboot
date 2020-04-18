#pragma once
#include <algorithm>
#include <set>

namespace p715
{
    // beautiful (stolen) solution that takes advantage of the fact that we need to maintain a disjointed set of intervals
    // the equal_range method in std::set is used to querry the set for overlapping intervals
    class RangeModule
    {
      public:
        RangeModule()
        {
        }

        void addRange(int left, int right)
        {
            auto [start, end] = _intervals.equal_range({left, right});
            if (start == end)
                _intervals.insert({left, right});
            else
            {
                int min_left = std::min(left, start->left);
                int max_right = std::max(right, std::prev(end)->right);
                _intervals.erase(start, end);
                _intervals.insert({min_left, max_right});
            }
        }

        bool queryRange(int left, int right)
        {
            auto [start, end] = _intervals.equal_range({left, right});
            if (start == end)
                return false;

            if (start == std::prev(end))
                return start->left <= left && start->right >= right;

            return false;
        }

        void removeRange(int left, int right)
        {
            auto [start, end] = _intervals.equal_range({left, right});
            if (start == end)
                return;

            int min_left = start->left;
            int max_right = std::prev(end)->right;
            _intervals.erase(start, end);

            if (min_left < left)
                _intervals.insert({min_left, left});

            if (max_right > right)
                _intervals.insert({right, max_right});
        }

      private:
        // intervals are disjointed.
        struct Interval
        {
            int left = 0;
            int right = 0;
            bool operator<(const Interval& other) const
            {
                return right < other.left;
            }
        };
        std::set<Interval> _intervals;
    };
}