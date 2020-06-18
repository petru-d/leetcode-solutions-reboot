#pragma once
#include <vector>

namespace p275
{
    class Solution
    {
      public:
        int hIndex(std::vector<int>& citations)
        {
            auto N = citations.size();

            auto ok = [&citations, N](int index) { return index >= N || citations[index] >= N - index; };

            int x = -1;
            for (int b = int(N); b >= 1; b /= 2)
            {
                while (!ok(x + b))
                    x += b;
            }

            return int(N) - x - 1;
        }
    };
}
