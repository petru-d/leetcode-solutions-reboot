#pragma once
#include <bitset>

namespace p371
{
    class Solution
    {
      public:
        int getSum2(int a, int b)
        {
            b += a;
            return b;
        }

        int getSum(int a, int b)
        {
            constexpr size_t sz = 8 * sizeof(int);

            std::bitset<sz> a_bits(a);
            std::bitset<sz> b_bits(b);
            std::bitset<sz> sum_bits(0);

            bool carry = false;
            for (size_t i = 0; i < sz; ++i)
            {
                sum_bits[i] = a_bits[i] ^ b_bits[i] ^ carry;
                // If at least two bits are on, the carry is on
                carry = (a_bits[i] && b_bits[i]) || (a_bits[i] && carry) || (carry && b_bits[i]);
            }

            return static_cast<int>(sum_bits.to_ulong());
        }
    };
}
