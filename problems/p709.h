#pragma once
#include <string>

namespace p709
{
    class Solution
    {
      public:
        std::string toLowerCase(std::string s)
        {
            for (auto& c : s)
            {
                if ('A' <= c && c <= 'Z')
                    c += 'a' - 'A';
            }

            return s;
        }
    };
}
