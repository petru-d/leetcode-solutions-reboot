#pragma once
#include <cstdint>

namespace p1342
{
    class Solution
    {
      public:
        int numberOfSteps(int num)
        {
            if (num == 0)
                return 0;

            int steps = 0;
            while (num != 1)
            {
                if (num & uint8_t(1))
                    ++steps;
                ++steps;
                num >>= 1;
            }

            return steps + 1;
        }
    };
}
