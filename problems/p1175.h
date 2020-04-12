#pragma once

#include <array>

namespace p1175
{
    class Solution
    {
      public:
        int numPrimeArrangements(int n)
        {
            // fi(n) is the number of primes smaller or equal to n
            // since prime numbers must be at prime indices, we can view primes as their own sub-permutation and the non-primes as
            // their own. so the answer is fi(n)! * (n - fi(n))!
            //(the number of permutations for the primes multiplied by the  number of permutations for the non primes)

            uint64_t res = fac_mod(fi(n)) * fac_mod(n - fi(n));

            res %= big_prime;

            return static_cast<int>(res);
        }

        uint64_t fac_mod(int n)
        {
            uint64_t res = 1;
            for (int i = 2; i <= n; ++i)
            {
                res *= i;
                if (res > big_prime)
                    res %= big_prime;
            }
            return res;
        }

        int fi(int n)
        {
            if (n <= 1)
                return 0;

            size_t i = 0;
            while (i < primes.size() && primes[i] <= n)
                ++i;

            return static_cast<int>(i);
        }

      private:
        const int big_prime = 1000000007;
        const std::array<int, 25> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                                            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    };
}
