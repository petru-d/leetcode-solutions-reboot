#pragma once

#include <string>

namespace p392
{
    class Solution
    {
      public:
        bool isSubsequence(std::string s, std::string t)
        {
            return isSubsequenceIndex(s, 0, t, 0);
        }
        bool isSubsequenceIndex(const std::string& s, size_t start_s, const std::string& t, size_t start_t)
        {
            if (start_s >= s.size())
                return true;

            auto pos = std::find(t.begin() + start_t, t.end(), s[start_s]);
            if (pos == t.end())
                return false;

            return isSubsequenceIndex(s, start_s + 1, t, 1 + std::distance(t.begin(), pos));
        }
    };
}
