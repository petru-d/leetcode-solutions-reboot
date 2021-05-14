#pragma once
#include <cmath>

namespace p204
{
    class Solution
    {
      public:
        int countPrimes(int n)
        {
            if (n <= 2)
                return 0;

            auto N = size_t(n - 1);

            std::vector<bool> sieve(N, true);
            sieve[0] = false;

            size_t p = 1;
            auto SN = sqrt(n - 1);
            while (p <= SN)
            {
                ++p;
                if (!sieve[p - 1])
                    continue;
                for (size_t i = p * p; i <= N; i += p)
                    sieve[i - 1] = false;
            }

            return int(std::count_if(sieve.begin(), sieve.end(), [](bool b) { return b; }));
        }
    };

    class Solution2
    {
      public:
        int countPrimes(int n)
        {
            std::array<uint8_t, 5000000> sieve = {};

            // sieve[i] == 0 means i is prime;
            sieve[0] = 1;
            sieve[1] = 1;
            int sqn = sqrt(n);
            int p = 2;
            while (p <= sqn)
            {
                if (sieve[p] == 1)
                {
                    ++p;
                    continue;
                }
                auto pp = 2 * p;
                while (pp < n)
                {
                    sieve[pp] = 1;
                    pp += p;
                }
                ++p;
            }
            return std::count(sieve.begin(), sieve.begin() + size_t(n), 0);
        }
    };
}
