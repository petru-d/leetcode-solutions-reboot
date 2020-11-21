#pragma once

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
}
