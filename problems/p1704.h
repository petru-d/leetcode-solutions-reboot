#pragma once
#include <string>

namespace p1704
{
    class Solution
    {
      public:
        bool halvesAreAlike(std::string s)
        {
            auto is_vowel = [](char c) {
                c = std::tolower(c);
                return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            };

            auto S = s.size();
            int diff = 0;
            for (size_t i = 0; i < S / 2; ++i)
                if (is_vowel(s[i]))
                    ++diff;
            for (size_t i = S / 2; i < S; ++i)
                if (is_vowel(s[i]))
                {
                    --diff;
                    if (diff < 0)
                        return false;
                }

            return diff == 0;
        }
    };
}
