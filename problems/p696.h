#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p696
{
    class Solution
    {
      public:
        int countBinarySubstrings(std::string s)
        {
            auto S = s.size();
            if (S == 0)
                return 0;

            size_t prev_window_size = 0;
            size_t curr_window_size = 1;

            size_t result = 0;
            for (size_t i = 1; i < S; ++i)
            {
                if (s[i] == s[i - 1])
                    ++curr_window_size;
                else
                {
                    result += std::min(prev_window_size, curr_window_size);
                    prev_window_size = curr_window_size;
                    curr_window_size = 1;
                }
            }

            result += std::min(prev_window_size, curr_window_size);

            return int(result);
        }
    };
}
