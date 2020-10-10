#pragma once
#include <deque>

namespace p933
{
    class RecentCounter
    {
      public:
        RecentCounter()
        {
        }

        int ping(int t)
        {
            times.push_back(t);

            auto pp = std::partition_point(times.begin(), times.end(), [t](auto tt) { return tt < t - 3000; });

            size_t dist = std::distance(times.begin(), pp);
            for (size_t i = 0; i < dist; ++i)
                times.pop_front();
            return int(times.size());
        }

        std::deque<int> times;
    };
}
