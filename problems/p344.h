#pragma once

#include <vector>

namespace p344
{
    class Solution
    {
      public:
        void reverseString(std::vector<char>& s)
        {
            auto S = s.size();
            for (size_t i = 0; i < S / 2; ++i)
                std::swap(s[i], s[S - i - 1]);
        }
    };
}