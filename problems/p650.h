#pragma once
#include <vector>

namespace p650
{
    class Solution
    {
      public:
        // similar approach: divide by 2 and add 2 until can't divide no more, then by 3, then by 5 etc
        // (or if too lazy to precompute primes, can also do by 2, by 3, by 4 etc - the non primes will exit immediatelly)
        int minSteps(int n)
        {
            if (n == 1)
                return 0;

            std::vector<int> primes = {
                2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,
                79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
                191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
                311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
                439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571,
                577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
                709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853,
                857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

            // steps[i] = number of steps for i + 1
            std::vector<int> steps(size_t(n), 0);

            for (size_t i = 1; i < size_t(n); ++i)
            {
                for (auto p : primes)
                    if ((i + 1) % p == 0)
                    {
                        steps[i] = p + steps[(i + 1) / p - 1];
                        break;
                    }
            }

            return steps.back();
        }
    };
}