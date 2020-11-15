#pragma once

namespace p458
{
    class Solution
    {
      public:
        int poorPigs(int buckets, int minutesToDie, int minutesToTest)
        {
            int tests = minutesToTest / minutesToDie;

            return int(ceil(log_b(tests + 1.0, buckets)));
        }

        double log_b(double base, double x)
        {
            return log(x) / log(base);
        }
    };

}
