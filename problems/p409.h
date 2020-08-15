#pragma once
#include <array>
#include <string>

namespace p409
{
    class Solution
    {
      public:
        int longestPalindrome(std::string s)
        {
            std::array<size_t, 52> n = {};

            for (const auto c : s)
            {
                if (c >= 'a')
                    ++n[26 + c - 'a'];
                else
                    ++n[c - 'A'];
            }

            bool found_odd = false;
            int result = 0;
            for (const auto lq : n)
            {
                result += 2 * (lq / 2);
                if (lq % 2 == 1)
                    found_odd = true;
            }

            return result + (found_odd ? 1 : 0);
        }
    };
}
