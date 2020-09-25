#pragma once
#include <array>
#include <string>

namespace p389
{
    class Solution
    {
      public:
        char findTheDifference(std::string s, std::string t)
        {
            std::array<size_t, 26> letters = {};
            for (auto tt : t)
                ++letters[size_t(tt) - 'a'];
            for (auto ss : s)
                --letters[size_t(ss) - 'a'];
            for (size_t i = 0; i < 26; ++i)
                if (letters[i] != 0)
                    return 'a' + i;

            return 0;
        }
    };

    // another nice solution is to xor everything in both strings the global xor result is the extra letter
}
