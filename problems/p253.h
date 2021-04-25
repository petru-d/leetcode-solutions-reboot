#pragma once
#include <algorithm>
#include <queue>
#include <vector>

namespace p253
{
    class Solution
    {
      public:
        int minMeetingRooms(std::vector<std::vector<int>>& intervals)
        {
            struct Point
            {
                int Time = -1;
                bool IsStart = false;
            };

            auto I = intervals.size();

            std::vector<Point> time_points(2 * I, Point{});

            for (auto i = 0; i < I; ++i)
            {
                time_points[2 * i] = Point{intervals[i][0], true};
                time_points[2 * i + 1] = Point{intervals[i][1], false};
            }

            std::sort(time_points.begin(), time_points.end(), [](const Point& l, const Point& r) {
                if (l.Time != r.Time)
                    return l.Time < r.Time;
                return !l.IsStart;
            });

            int max_depth = 0;
            int curr_depth = 0;
            for (const auto& p : time_points)
            {
                if (p.IsStart)
                {
                    ++curr_depth;
                    max_depth = std::max(max_depth, curr_depth);
                }
                else
                    --curr_depth;
            }

            return max_depth;
        }
    };

    class Solution2
    {
      public:
        int minMeetingRooms(std::vector<std::vector<int>>& intervals)
        {
            auto I = intervals.size();

            std::sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r) { return l[0] < r[0]; });

            // keep end times in a min heap. when a new meeting starts (they are sorted by start time),
            // check if it starts earlier than the one running that currently ends earliest
            // - no? then we allocate a new room
            // - yes? no new room needed
            std::priority_queue<int, std::vector<int>, std::greater<int>> taken_rooms;

            size_t max_depth = 0;
            for (const auto& i : intervals)
            {
                if (taken_rooms.empty() || taken_rooms.top() > i[0])
                {
                    taken_rooms.push(i[1]);
                    max_depth = std::max(max_depth, taken_rooms.size());
                }
                else
                {
                    taken_rooms.pop();
                    taken_rooms.push(i[1]);
                }
            }

            return int(max_depth);
        }
    };
}
