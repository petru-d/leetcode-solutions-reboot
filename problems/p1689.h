#pragma once
#include <algorithm>
#include <string>

namespace p1689
{
    class Solution2
    {
      public:
        int minPartitions(std::string n)
        {
            return *std::max_element(n.begin(), n.end()) - '0';
        }
    };

    class Solution
    {
      public:
        int minPartitions(std::string n)
        {
            char max = 0;
            for (const auto c : n)
            {
                max = std::max(max, c);
                if (max == '9')
                    return 9;
            }

            return max - '0';
        }
    };
}
