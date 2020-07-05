#pragma once

namespace p461
{
    class Solution
    {
      public:
        int hammingDistance(int x, int y)
        {
            return bitz(x ^ y);
        }

      private:
        int bitz(int n)
        {
            int res = 0;
            while (n != 0)
            {
                res++;
                n = n & (n - 1);
            }

            return res;
        }
    };
}
