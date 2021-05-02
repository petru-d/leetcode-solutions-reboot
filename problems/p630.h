#pragma once
#include <queue>
#include <vector>

namespace p630
{
    class Solution
    {
      public:
        int scheduleCourse(std::vector<std::vector<int>>& courses)
        {
            // state is curr_end_day, number of used days, max heap with lengths of courses taken

            // new course:
            // - takes longer than its end day - skip
            // - new end day is new course end day
            // - does it fit? take it for free
            // - it doesn't fit
            //   - is it a better choice than the top of the heap - swap it
            //   - not a better choice - skip

            std::sort(courses.begin(), courses.end(),
                      [](const std::vector<int>& l, const std::vector<int>& r) { return l[1] < r[1]; });

            std::priority_queue<int> taken_courses;
            int end_day = 1;
            int used_days = 0; // sum of the heap
            int taken_total = 0;

            for (const auto& c : courses)
            {
                end_day = c[1];
                auto curr_duration = c[0];

                // skip it if it takes more time than the end day
                if (curr_duration > end_day)
                    continue;

                // does it fit without discarding anything? take it
                if (used_days + curr_duration <= end_day)
                {
                    ++taken_total;
                    taken_courses.push(curr_duration);
                    used_days += curr_duration;
                    continue;
                }

                auto biggest_cost = taken_courses.top();

                // taking this course won't improve our status
                if (biggest_cost <= curr_duration)
                    continue;

                // swap the costliest course with this one
                taken_courses.pop();
                taken_courses.push(curr_duration);
                used_days = used_days - biggest_cost + curr_duration;
            }

            return taken_total;
        }
    };
}
