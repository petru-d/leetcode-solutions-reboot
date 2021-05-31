#pragma once
#include <queue>
#include <vector>

namespace p1167
{
    class Solution
    {
      public:
        int connectSticks(std::vector<int>& sticks)
        {
            std::priority_queue<int, std::vector<int>, std::greater<int>> curr_lengths(sticks.begin(), sticks.end());

            int cost = 0;
            while (curr_lengths.size() >= 2)
            {
                auto s1 = curr_lengths.top();
                curr_lengths.pop();
                auto s2 = curr_lengths.top();
                curr_lengths.pop();
                curr_lengths.push(s1 + s2);
                cost += s1 + s2;
            }

            return cost;
        }
    };
}
