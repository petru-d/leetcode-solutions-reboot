#pragma once
#include <unordered_set>

namespace p1015
{
    class Solution
    {
      public:
        int smallestRepunitDivByK(int K)
        {
            if (K % 2 == 0 || K % 5 == 0)
                return -1;

            std::unordered_set<int> remainders;

            int curr = 1;
            int total = 1;
            while (true)
            {
                auto [q, r] = div(curr, K);
                if (r == 0)
                    return total;

                auto pos = remainders.find(r);
                if (pos != remainders.end())
                    return -1;
                remainders.insert(r);

                curr = 10 * r + 1;
                ++total;
            }

            return -1;
        }
    };
}
