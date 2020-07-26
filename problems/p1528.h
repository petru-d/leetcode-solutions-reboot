#pragma once

#include <string>
#include <vector>

namespace p1528
{
    class Solution
    {
      public:
        std::string restoreString(std::string s, std::vector<int>& indices)
        {
            size_t N = s.size();
            for (size_t i = 0; i < N; ++i)
            {
                while (indices[i] != i)
                {
                    std::swap(s[i], s[indices[i]]);
                    std::swap(indices[i], indices[indices[i]]);
                }
            }

            return s;
        }
    };
}
