#pragma once
#include <set>

namespace p729
{
    class MyCalendar
    {
      public:
        MyCalendar()
        {
        }

        bool book(int start, int end)
        {
            Interval i{start, end};

            auto [low, high] = meetings.equal_range(i);
            if (low != high)
                return false;

            meetings.insert(i);
            return true;
        }

        struct Interval
        {
            int Start = -1;
            int End = -1;
            bool operator<(const Interval& other) const
            {
                return End <= other.Start;
            }
        };
        std::set<Interval> meetings;
    };
}
