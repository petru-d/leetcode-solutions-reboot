#pragma once

#include <string>

namespace p125
{
    class Solution
    {
      public:
        bool isPalindrome(std::string s)
        {
            if (s.empty())
                return true;

            size_t l = 0;
            size_t r = s.size() - 1;

            while (l < r)
            {
                auto lc = static_cast<unsigned char>(s[l]);
                auto rc = static_cast<unsigned char>(s[r]);
                if (!std::isalnum(lc))
                {
                    ++l;
                    continue;
                }
                if (!std::isalnum(rc))
                {
                    --r;
                    continue;
                }

                if (l == r)
                    return true;

                if (std::toupper(lc) != std::toupper(rc))
                    return false;
                ++l;
                --r;
            }

            return true;
        }
    };
}
