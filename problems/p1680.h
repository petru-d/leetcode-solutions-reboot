#pragma once

namespace p1680
{
    class Solution
    {
      public:
        int concatenatedBinary(int n)
        {
            int M = 1000000007;
            uint64_t result = 1;
            for (int i = 2; i <= n; ++i)
            {
                int curr = i;
                size_t c = 0;
                while (curr != 0)
                {
                    curr >>= 1;
                    ++c;
                }
                result <<= c;
                result |= i;
                result %= M;
            }

            return int(result);
        }
    };
}
