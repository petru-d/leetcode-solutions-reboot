#pragma once
#include <unordered_set>
#include <vector>

namespace p575
{
    class Solution
    {
      public:
        int distributeCandies(std::vector<int>& candyType)
        {
            auto half = candyType.size() / 2;
            std::unordered_set<int> eaten;
            for (const auto ct : candyType)
            {
                auto pos = eaten.find(ct);
                if (pos == eaten.end())
                    eaten.insert(ct);
                if (eaten.size() >= half)
                    return half;
            }

            return eaten.size();
        }
    };
}
