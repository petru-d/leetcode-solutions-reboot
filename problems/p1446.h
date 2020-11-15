#pragma once
#include <string>

namespace p1446
{
    class Solution
    {
      public:
        int maxPower(std::string s)
        {
            auto S = s.size();
            if (S == 0)
                return 0;

            int power = 1;
            int curr = 1;
            for (size_t i = 1; i < S; ++i)
            {
                if (s[i] == s[i - 1])
                {
                    ++curr;
                    power = std::max(power, curr);
                }
                else
                {
                    curr = 1;
                }
            }

            return power;
        }
    };
}
