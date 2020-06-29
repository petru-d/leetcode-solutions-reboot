#pragma once

#include <cstdint>

namespace p62
{
    class Solution
    {
      public:
        int uniquePaths(int m, int n)
        {
            uint64_t N = m - 1 + n - 1;
            uint64_t K = m - 1;
            return static_cast<int>(comb(N, K));
        }

      private:
        uint64_t comb(uint64_t n, uint64_t k)
        {
            if (k == 0 || k == n)
                return 1;

            if (k < n / 2)
                k = n - k;

            // n! / k!(n-k)!
            // (k+1)(k+2)...n / 1*2*...(n-k)
            // n(n-1)...(k+1) / 1*2*...(n-k)

            uint64_t result = n;
            for (uint64_t i = n - 1; i >= k + 1; --i)
            {
                result *= i;
                result /= (n - i + 1);
            }

            return result;
        }
    };
}
