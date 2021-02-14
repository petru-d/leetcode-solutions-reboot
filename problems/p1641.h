#pragma once

namespace p1641
{
    class Solution
    {
      public:
        int countVowelStrings(int n)
        {
            if (n == 1)
                return 5;

            int res = 0;
            for (int k = 1; k <= n + 1; ++k)
                res += k * (k + 1) / 2 * (n + 2 - k);

            return res; // or combs(n, 5) ffs
        }
    };
}
