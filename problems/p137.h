#pragma once

#include <array>
#include <cassert>
#include <iostream>
#include <vector>

/*
class Solution {
  public int singleNumber(int[] nums) {
    int seenOnce = 0, seenTwice = 0;

    for (int num : nums) {
      // first appearence:
      // add num to seen_once
      // don't add to seen_twice because of presence in seen_once

      // second appearance:
      // remove num from seen_once
      // add num to seen_twice

      // third appearance:
      // don't add to seen_once because of presence in seen_twice
      // remove num from seen_twice
      seenOnce = ~seenTwice & (seenOnce ^ num);
      seenTwice = ~seenOnce & (seenTwice ^ num);
    }

    return seenOnce;
  }
}
*/

namespace p137
{
    constexpr size_t trit_count = 20;
    using base_3_bits = std::array<uint8_t, trit_count>;

    class Solution
    {
        void my_xor(base_3_bits& storage, uint32_t x)
        {
            auto to_base_3 = [](uint32_t n) {
                base_3_bits res = {};

                size_t pos = 0;
                while (n != 0)
                {
                    auto [q, r] = lldiv(n, 3);
                    res[pos++] = static_cast<uint8_t>(r);
                    n = static_cast<uint32_t>(q);
                }

                return res;
            };

            // To base 3 trits.
            auto x_3 = to_base_3(x);

            // Store with extended xor.
            for (size_t i = 0; i < trit_count; ++i)
                storage[i] = (storage[i] + x_3[i]) % 3;
        }

      public:
        int singleNumber(std::vector<int>& nums)
        {
            // Store the trits here.
            // Since I don't want to deal with negatives, just keep everything positive and remember the sign.
            base_3_bits res_3 = {};
            int sign = 0;
            for (auto n : nums)
            {
                if (n < 0)
                {
                    --sign;
                    my_xor(res_3, uint32_t(-int64_t(n)));
                }
                else
                {
                    ++sign;
                    my_xor(res_3, uint32_t(n));
                }
            }

            auto to_base_10 = [](const base_3_bits& bits) {
                uint64_t res = 0;
                uint64_t pow = 1;
                for (size_t i = 0; i < trit_count; ++i)
                {
                    res += pow * bits[i];
                    pow *= 3;
                }

                return uint32_t(res);
            };

            // Return the storage converted to base 10.
            return sign < 0 ? -int64_t(to_base_10(res_3)) : int64_t(to_base_10(res_3));
        }
    };
}
