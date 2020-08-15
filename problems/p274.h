#pragma once
#include <algorithm>
#include <vector>

namespace p274
{
    class Solution
    {
      public:
        int hIndex(std::vector<int>& citations)
        {
            auto N = citations.size();

            std::vector<int> buckets(N + 1, 0);
            for (const auto c : citations)
            {
                ++buckets[std::min(N, static_cast<size_t>(c))];
            }
            int h = 0;
            for (size_t i = N + 1; i >= 1; --i)
            {
                h += buckets[i - 1];
                if (h >= i - 1)
                    return int(i) - 1;
            }
            return -1;
        }
    };
}
