#pragma once
#include <bitset>

namespace p231
{
    class Solution
    {
      public:
        bool isPowerOfTwo(int n)
        {
            if (n <= 0)
                return false;

            std::bitset<8 * sizeof(int)> b(n);

            return b.count() == 1;
        }
    };
}