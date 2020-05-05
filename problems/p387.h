#pragma once
#include <algorithm>
#include <array>
#include <string>

namespace p387
{
    class Solution
    {
      public:
        int firstUniqChar(std::string s)
        {
            if (s.empty())
                return -1;

            std::array<int, 26> first_occ;
            std::fill(first_occ.begin(), first_occ.end(), std::numeric_limits<int>::max());
            for (size_t i = 0; i < s.size(); ++i)
            {
                if (first_occ[s[i] - 'a'] == std::numeric_limits<int>::max())
                    first_occ[s[i] - 'a'] = static_cast<int>(i);
                else
                    first_occ[s[i] - 'a'] = std::numeric_limits<int>::max() - 1;
            }

            int res = *std::min_element(first_occ.begin(), first_occ.end());
            return ((res == std::numeric_limits<int>::max() - 1) ? -1 : res);
        }
    };
}