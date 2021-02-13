#pragma once
#include <vector>
#include <algorithm>

namespace p744
{
    class Solution
    {
      public:
        char nextGreatestLetter(std::vector<char>& letters, char target)
        {
            auto [low, high] = std::equal_range(letters.begin(), letters.end(), target);

            if (high == letters.end())
                return letters.front();

            return *high;
        }
    };
}
