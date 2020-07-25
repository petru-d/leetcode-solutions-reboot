#pragma once

#include <cassert>
#include <numeric>
#include <queue>
#include <vector>

namespace p1354
{
    class Solution
    {
      public:
        bool isPossible(std::vector<int>& target)
        {
            std::priority_queue<uint64_t> q(target.begin(), target.end());

            auto curr_sum = std::accumulate(target.begin(), target.end(), uint64_t(0));

            while (true)
            {
                auto top = q.top();
                if (top == 1)
                    return true;

                auto rest_sum = curr_sum - top;
                if (rest_sum == 1)
                    return true;

                if (rest_sum == 0 || top <= rest_sum || top % rest_sum == 0)
                    return false;

                q.pop();
                q.push(top % rest_sum);
                curr_sum = curr_sum - top + (top % rest_sum);
            }

            assert(false);
            return false;
        }
    };
}
