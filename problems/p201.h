#pragma once
#include <bitset>

namespace p201
{
    class Solution
    {
      public:
        int rangeBitwiseAnd_(int m, int n)
        {
            std::bitset<32> m_bits(m);
            std::bitset<32> n_bits(n);

            std::bitset<32> res_bits(0);

            size_t curr = 32;
            while (curr >= 1 && m_bits[curr - 1] == n_bits[curr - 1])
            {
                res_bits[curr - 1] = m_bits[curr - 1];
                --curr;
            }
            while (curr >= 1)
            {
                res_bits[curr - 1] = false;
                --curr;
            }

            return static_cast<int>(res_bits.to_ulong());
        }

        int rangeBitwiseAnd(int m, int n)
        {
            size_t shift = 32;

            while (shift >= 1 && ((m & (1ul << (shift - 1))) == (n & (1ul << (shift - 1)))))
                --shift;

            if (shift == 32)
                return 0;
            if (shift == 0)
                return m;

            return m & (((1ul << (32 - shift)) - 1) << shift);
        }
    };
}