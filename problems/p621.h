#pragma once
#include <algorithm>
#include <array>
#include <vector>

namespace p621
{
    class Solution
    {
      public:
        int leastInterval(std::vector<char>& tasks, int n)
        {
            std::array<size_t, 26> task_sizes = {};

            for (auto t : tasks)
            {
                ++task_sizes[t - 'A'];
            }

            size_t tasks_count = std::count_if(task_sizes.begin(), task_sizes.end(), [](size_t t) { return t != 0; });

            size_t biggest_task = *std::max_element(task_sizes.begin(), task_sizes.end());

            size_t biggest_count =
                std::count_if(task_sizes.begin(), task_sizes.end(), [biggest_task](size_t t) { return t == biggest_task; });

            size_t fit_biggest = (biggest_task - 1) * (n + 1) + biggest_count;

            return static_cast<int>((n >= tasks_count - 1) ? fit_biggest : std::max(tasks.size(), fit_biggest));
        }
    };
}