#pragma once
#include <string>

namespace p58
{
    class Solution
    {
      public:
        int lengthOfLastWord(std::string s)
        {
            auto startPos = std::rbegin(s);
            while (*startPos == ' ')
                ++startPos;
            auto pos = std::find(startPos, std::rend(s), ' ');
            return static_cast<int>(std::distance(startPos, pos));
        }
    };
}
