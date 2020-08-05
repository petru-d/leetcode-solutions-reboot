#pragma once
#include <array>

namespace p342
{
    class Solution
    {
      public:
        bool isPowerOfFour(int num)
        {
            if (num <= 0)
                return false;

            constexpr std::array<std::uint8_t, 4> valid_non_zero = {1, 4, 16, 64};

            size_t zero_count = 0;

            auto apply_byte = [&zero_count, &valid_non_zero](uint8_t b) {
                if (b != 0 && b != valid_non_zero[0] && b != valid_non_zero[1] && b != valid_non_zero[2] &&
                    b != valid_non_zero[3])
                    return false;
                else if (b == 0)
                    ++zero_count;
                return true;
            };

            if (!apply_byte(num & 0xff))
                return false;
            if (!apply_byte((num >> 8) & 0xff))
                return false;
            if (!apply_byte((num >> 16) & 0xff))
                return false;
            if (!apply_byte((num >> 24) & 0xff))
                return false;

            return zero_count == 3;
        }
    };
}
