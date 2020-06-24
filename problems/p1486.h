#pragma once

namespace p1486
{
    class Solution
    {
      public:
        int xorOperation(int n, int start)
        {
            // consecutives xor nicely. remember the last bit, solve the problem for (start/2, start/2 + 1, start/2 + 2 etc), and
            // then put the last bit back.

            int last_bit = (start & 1) & (n & 1);

            int res = consecutives_xor(n, start >> 1);

            return (res << 1) | last_bit;
        }

      private:
        int consecutives_xor(int n, int start)
        {
            // because 2k ^ 2k+1 = 1, we want to make start even

            if (start & 1)
            {
                // if start is odd, start earlier and then cancel the fake start
                return consecutives_xor_even_start(n + 1, start - 1) ^ (start - 1);
            }

            return consecutives_xor_even_start(n, start);
        }

        int consecutives_xor_even_start(int n, int start)
        {
            // group (start, start + 1), (start + 2, start + 3) etc
            // since start is even, each group will be a one
            if (n & 1)
            {
                // n is odd: we have (n-1) / 2 ones and (start + n - 1)
                return xor_n_ones((n - 1) >> 1) ^ (start + n - 1);
            }

            return xor_n_ones(n >> 1);
        }

        int xor_n_ones(int n)
        {
            return n & 1;
        }
    };
}
