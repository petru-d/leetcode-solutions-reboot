#pragma once
#include <vector>

namespace p881
{
    class Solution
    {
      public:
        int numRescueBoats(std::vector<int>& people, int limit)
        {
            size_t N = people.size();
            if (N <= 1)
                return 1;

            std::sort(people.begin(), people.end());

            size_t l = 0;
            size_t r = N - 1;

            size_t result = 0;
            while (l <= r)
            {
                if (people[l] >= limit || l == r)
                {
                    result += r - l + 1;
                    break;
                }
                if (people[r] >= limit)
                {
                    ++result;
                    --r;
                    continue;
                }

                if (people[l] + people[r] <= limit)
                {
                    ++result;
                    ++l;
                    --r;
                    continue;
                }

                ++result;
                --r;
            }

            return int(result);
        }
    };
}
