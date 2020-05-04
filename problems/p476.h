#pragma once
namespace p476
{
    class Solution
    {
      public:
        int findComplement(int num)
        {
            size_t shift = 0;
            while (!(num & (1 << 31ul)))
            {
                ++shift;
                num <<= 1;
            }
            num >>= shift;
            return ~num;
        }
    };

}