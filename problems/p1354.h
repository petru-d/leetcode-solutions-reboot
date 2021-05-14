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

    // sum  A
    // sum  A + sum
    // sum  A + 2*sum
    // ...
    // sum  A + k*sum
    class Solution2
    {
      public:
        bool isPossible(std::vector<int>& target)
        {
            if (target.size() == 1)
                return target[0] == 1;

            std::priority_queue<uint64_t> nums;
            uint64_t total_sum = 0;
            for (auto t : target)
            {
                nums.push(t);
                total_sum += t;
            }

            while (true)
            {
                auto big = nums.top();
                if (big == 1)
                    return true;

                auto rest_sum = total_sum - big;

                if (big <= rest_sum)
                    return false;

                // replace big with big % rest_sum (basically do the substraction multiple times at once)
                auto [q, new_big] = std::lldiv(big, rest_sum);

                if (new_big == 0)
                    new_big = rest_sum;

                nums.pop();
                nums.push(new_big);

                total_sum = total_sum - big + new_big;
            }

            assert(false);
            return false;
        }
    };
}
