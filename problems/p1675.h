#pragma once
#include <limits>
#include <queue>
#include <vector>

namespace p1675
{
    class Solution
    {
      public:
        int minimumDeviation(std::vector<int>& nums)
        {
            auto cmp = [](const std::pair<int, int>& l, const std::pair<int, int>& r) { return l.first > r.first; };

            // keep a min heap with pairs between the minimum and maximum possibilities for a number
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp);

            int min = std::numeric_limits<int>::max();
            int max = std::numeric_limits<int>::min();

            for (const auto& n : nums)
            {
                if (n % 2 == 1)
                {
                    q.emplace(n, 2 * n);
                    min = std::min(min, n);
                    max = std::max(max, n);
                }
                else
                {
                    auto n_min = n;
                    while (n_min % 2 == 0)
                        n_min /= 2;
                    q.emplace(n_min, n);
                    min = std::min(min, n_min);
                    max = std::max(max, n_min);
                }
            }

            // take one element from the heap, update the best solution, put it back with the next possibility for its value
            int best_sol = max - min;
            bool done = false;
            while (!q.empty())
            {
                auto [curr_min, curr_max] = q.top();

                best_sol = std::min(best_sol, max - curr_min);

                // if the current number has no where else to go, the solution cannot be improved anymore
                if (curr_min == curr_max)
                    break;

                max = std::max(max, 2 * curr_min);

                q.pop();
                q.emplace(2 * curr_min, curr_max);
            }

            return best_sol;
        }
    };
}
