#pragma once
#include <string>
namespace p171
{
    class Solution
    {
      public:
        int titleToNumber(std::string s)
        {
            auto char_val = [](char c) { return c - 'A' + 1; };

            int result = 0;
            size_t pow26 = 1;

            auto ss = s.size();
            for (size_t i = ss; i >= 1; --i)
            {
                result += char_val(s[i - 1]) * static_cast<int>(pow26);
                pow26 *= 26;
            }

            return result;
        }
    };
}