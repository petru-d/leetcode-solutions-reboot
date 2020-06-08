#pragma once
#include <cmath>

namespace p70
{
    class Solution
    {
      public:
        int climbStairs(int n)
        {
            if (n <= 3)
                return n;

            // sol[n] = sol[n-1] + sol[n-2]
            //(all combos till n-1, then climb the last step alone) + (all combos till n-2 and climb the last 2 steps at once)

            // the only difference to fibonacci is that it doesn't start from 0, 1, 1, but rather 0, 1, 2
            // so our sol(n) = fibo(n + 1)

            // closed form for fibonacci(n+1)
            double fi = (1 + sqrt(5)) / 2;
            return static_cast<int>(std::floor(pow(fi, n + 1) / sqrt(5) + 0.5));
        }
    };
}