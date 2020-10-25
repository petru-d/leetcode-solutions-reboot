#pragma once
#include <algorithm>
#include <string>

namespace p345
{
    class Solution
    {
      public:
        std::string reverseVowels(std::string s)
        {
            size_t S = s.size();
            if (S == 0)
                return s;

            size_t l = 0;
            size_t r = s.size() - 1;

            auto vowel = [&s](size_t pos) {
                return s[pos] == 'a' || s[pos] == 'e' || s[pos] == 'i' || s[pos] == 'o' || s[pos] == 'u' || s[pos] == 'A' ||
                       s[pos] == 'E' || s[pos] == 'I' || s[pos] == 'O' || s[pos] == 'U';
            };

            while (l < r)
            {
                while (l < S && !vowel(l))
                    ++l;
                while (r > l && !vowel(r))
                    --r;
                if (l >= r)
                    break;
                std::swap(s[l], s[r]);
                ++l;
                --r;
            }

            return s;
        }
    };
}
