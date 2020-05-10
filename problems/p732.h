#pragma once

#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
namespace p732
{
    class MyCalendarThree
    {
      public:
        MyCalendarThree()
        {
        }

        int book(int start, int end)
        {
            Interval i{start, end, 1};
            auto [l, r] = _intervals.equal_range(i);

            if (l == r)
            {
                _intervals.insert(i);
                _max_book_level = std::max(size_t(1), _max_book_level);
            }
            else if (l == std::prev(r))
            {
                auto split = *l;
                _intervals.erase(l);

                auto splits = split_interval(split, start, end);
                _intervals.insert(splits.begin(), splits.end());
                _max_book_level = std::max(split.book_level + 1, _max_book_level);
            }
            else // if (l != std::prev(r))
            {
                for (auto it = std::next(l); it != std::prev(r); ++it)
                {
                    ++(it->book_level);
                    _max_book_level = std::max(it->book_level, _max_book_level);
                }

                auto split_left = *l;
                _intervals.erase(l);

                auto splits_left = split_interval_left(split_left, start);
                _intervals.insert(splits_left.begin(), splits_left.end());
                _max_book_level = std::max(split_left.book_level + 1, _max_book_level);

                auto split_right = *std::prev(r);
                _intervals.erase(std::prev(r));

                auto splits_right = split_interval_right(split_right, end);
                _intervals.insert(splits_right.begin(), splits_right.end());
                _max_book_level = std::max(split_right.book_level + 1, _max_book_level);
            }

            return static_cast<int>(_max_book_level);
        }

      private:
        // keep disjointed intervals, together with book level
        struct Interval
        {
            int start = -1;
            int end = -1;
            mutable size_t book_level = 0;
            bool operator<(const Interval& right) const
            {
                return end <= right.start;
            }
        };
        std::set<Interval> _intervals;

        std::vector<Interval> split_interval_left(const Interval& to_split, int point)
        {
            assert(point <= to_split.end);

            if (point == to_split.start)
            {
                return {{to_split.start, to_split.end, to_split.book_level + 1}};
            }

            Interval left;
            Interval right;
            if (point > to_split.start)
            {
                left = {to_split.start, point, to_split.book_level};
                right = {point, to_split.end, to_split.book_level + 1};
            }
            else
            {
                left = {point, to_split.start, 1};
                right = {to_split.start, to_split.end, to_split.book_level + 1};
            }

            return {left, right};
        }

        std::vector<Interval> split_interval_right(const Interval& to_split, int point)
        {
            assert(point > to_split.start);

            if (point == to_split.end)
            {
                return {{to_split.start, to_split.end, to_split.book_level + 1}};
            }

            Interval left, right;
            if (point < to_split.end)
            {
                left = {to_split.start, point, to_split.book_level + 1};
                right = {point, to_split.end, to_split.book_level};
            }
            else
            {
                left = {to_split.start, to_split.end, to_split.book_level + 1};
                right = {to_split.end, point, 1};
            }
            return {left, right};
        }

        std::vector<Interval> split_interval(const Interval& to_split, int start, int end)
        {
            std::vector<int> edges{to_split.start, to_split.end, start, end};
            std::sort(edges.begin(), edges.end());
            edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

            if (edges.size() == 4)
            {
                Interval left{edges[0], edges[1], 0};
                Interval mid{edges[1], edges[2], to_split.book_level + 1};
                Interval right{edges[2], edges[3], 0};

                left.book_level = 1;
                right.book_level = 1;
                if (to_split.start < start && end < to_split.end)
                {
                    left.book_level = to_split.book_level;
                    right.book_level = to_split.book_level;
                }

                return {left, mid, right};
            }
            else if (edges.size() == 3)
            {
                Interval left{edges[0], edges[1], 0};
                Interval right{edges[1], edges[2], 0};

                if (start == to_split.start)
                {
                    left.book_level = to_split.book_level + 1;
                    right.book_level = to_split.end < end ? 1 : to_split.book_level;
                }
                else if (end == to_split.end)
                {
                    left.book_level = start < to_split.start ? 1 : to_split.book_level;
                    right.book_level = to_split.book_level + 1;
                }
                else
                {
                    assert(false);
                }
                return {left, right};
            }
            else if (edges.size() == 2)
            {
                return {{to_split.start, to_split.end, to_split.book_level + 1}};
            }
            else
            {
                assert(false);
                return {};
            }
        }
        size_t _max_book_level = 0;
    };
}