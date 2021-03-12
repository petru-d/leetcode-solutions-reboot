#pragma once
#include <string>
#include <vector>

namespace p1461
{
    class Solution
    {
      public:
        bool hasAllCodes(std::string s, int k)
        {
            auto S = s.size();
            if (S < k)
                return false;

            std::vector<int> found(1 << k, 0);

            size_t to_find = 1 << k;

            int curr = 0;
            for (size_t i = 0; i < k; ++i)
                curr |= ((s[i] - '0') << i);
            found[curr] = 1;

            size_t found_count = 1;

            for (size_t i = k; i < S; ++i)
            {
                curr >>= 1;
                curr |= ((s[i] - '0') << (k - 1));
                if (found[curr] == 0)
                {
                    found[curr] = 1;
                    ++found_count;
                    if (found_count == to_find)
                        return true;
                }
            }

            return false;
        }
    };
}
