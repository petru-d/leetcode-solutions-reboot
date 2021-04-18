#pragma once

namespace p509
{
    class Solution
    {
      public:
        int fib(int n)
        {
            if (n <= 1)
                return n;
            int prev_prev = 0;
            int prev = 1;
            int curr = -1;
            for (int i = 2; i <= n; ++i)
            {
                curr = prev_prev + prev;
                prev_prev = prev;
                prev = curr;
            }

            return curr;
        }
    };
}
