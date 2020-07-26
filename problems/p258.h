#pragma once
#include <cstdlib>

namespace p258
{
    class Solution
    {
      public:
        int addDigits(int num)
        {
            while (num >= 10)
            {
                int new_num = 0;
                while (num > 0)
                {
                    auto [q, r] = div(num, 10);
                    new_num += r;
                    num = q;
                }
                num = new_num;
            }

            return num;
        }
    };
}
