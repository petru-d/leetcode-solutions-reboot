#pragma once

namespace p1551
{
    class Solution
    {
      public:
        int minOperations(int n)
        {
            // n even -> 1 3 5 7 9 11 -> 5 + 3 + 1 -> 1 + 3 + ... + n - 1 -> (n/2)^2
            //       n^2 / 4
            // n odd -> 1 3 5 7 9 -> 4 + 2 + 0 -> 2 + 4 + ... + n - 1 -> 2 * (1 + 2 + ... + (n - 1) / 2) -> (n - 1)(n + 1) / 4
            //      (n^2 - 1) / 4

            return n % 2 == 0 ? n * n / 4 : (n * n - 1) / 4;
        }
    };
}
