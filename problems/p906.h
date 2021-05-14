#pragma once
#include <cmath>
#include <string>

namespace p906
{
    class Solution
    {
      public:
        int superpalindromesInRange(std::string left, std::string right)
        {
            auto left_num = to_num(left);
            auto right_num = to_num(right);

            auto low = std::ceil(sqrt(left_num));
            auto high = std::floor(sqrt(right_num));

            auto low_digits = digits_count(low);
            auto high_digits = digits_count(high);

            if (low_digits == high_digits)
                get_super(low_digits, low, high);
            else
            {
                get_super(low_digits, low, all_nines(low_digits));
                get_super(high_digits, one_zeroes(high_digits), high);
                for (auto i = low_digits + 1; i <= high_digits - 1; ++i)
                    get_super(i, one_zeroes(i), all_nines(i));
            }

            return super;
        }

        void get_super(int digit_count, uint64_t low, uint64_t high)
        {
            int half_digits = digit_count / 2 + digit_count % 2;
            uint64_t start = one_zeroes(half_digits);
            uint64_t end = all_nines(half_digits);
            for (uint64_t curr = start; curr <= end; ++curr)
            {
                uint64_t small_pali = mirror(curr, digit_count % 2 == 1);

                if (small_pali > high)
                    break;

                if (small_pali < low)
                    continue;

                if (is_palindrome(small_pali * small_pali))
                {
                    ++super;
                }
            }
        }

        uint64_t mirror(uint64_t num, bool odd_mirror)
        {
            auto result = num;

            auto half_digits = digits_count(num);

            for (int i = 1; i <= half_digits - (odd_mirror ? 1 : 0); ++i)
                result *= 10;

            if (odd_mirror)
                num /= 10;

            result += reverse(num);

            return result;
        }

        bool is_palindrome(uint64_t num)
        {
            return num == reverse(num);
        }

        uint64_t reverse(uint64_t num)
        {
            uint64_t result = 0;
            while (num != 0)
            {
                auto curr_digit = num % 10;
                num = num / 10;

                result = result * 10 + curr_digit;
            }

            return result;
        }

        uint64_t to_num(const std::string& data)
        {
            uint64_t result = 0;
            uint64_t factor = 1;
            for (auto it = data.rbegin(); it != data.rend(); ++it)
            {
                result += (*it - '0') * factor;
                factor *= 10;
            }

            return result;
        }

        uint64_t all_nines(int digit_count)
        {
            uint64_t result = 0;

            for (int i = 1; i <= digit_count; ++i)
                result = result * 10 + 9;

            return result;
        }

        uint64_t one_zeroes(int digit_count)
        {
            uint64_t result = 1;
            for (int i = 1; i < digit_count; ++i)
                result *= 10;
            return result;
        }

        int digits_count(uint64_t num)
        {
            int result = 0;
            while (num != 0)
            {
                ++result;
                num /= 10;
            }

            return result;
        }

        int super = 0;
    };
}
