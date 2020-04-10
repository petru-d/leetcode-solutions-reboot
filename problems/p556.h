#pragma once
#include <algorithm>
#include <optional>
#include <vector>

namespace p556
{
    class Solution
    {
      public:
        int nextGreaterElement(int n)
        {
            if (n == 0)
                return -1;

            std::vector<unsigned char> digits = digitize(n);

            // find the right-most position where two digits are strictly ascending:
            //...digits_front ... D1 < D2 >= D3 >= D4 >= D5 ...

            // if no such thing exists, our number is maximal - return -1

            // else, to construct our result,
            // - keep everthing before D1 the same
            // - replace D1 with the smallest of D2, D3... which is still strictly bigger than D1
            // - put the remaining digits after D1 in ascending order

            auto D1_index_opt = find_last_ascending(digits);
            if (!D1_index_opt)
                return -1;

            size_t D1_index = D1_index_opt.value();
            size_t swap_index = D1_index + 1;
            for (size_t i = D1_index + 2; i < digits.size(); ++i)
                if (digits[i] > digits[D1_index] && digits[i] < digits[swap_index])
                {
                    swap_index = i;
                }

            std::swap(digits[D1_index], digits[swap_index]);

            std::sort(digits.begin() + D1_index + 1, digits.end());

            // detects overflow
            auto result_opt = undigitize(digits);
            if (!result_opt)
                return -1;
            return result_opt.value();
        }

      private:
        std::vector<unsigned char> digitize(int n)
        {
            std::vector<unsigned char> result;

            while (n != 0)
            {
                auto res = lldiv(n, 10);
                n = static_cast<int>(res.quot);
                result.push_back(static_cast<unsigned char>(res.rem));
            }

            std::reverse(result.begin(), result.end());
            return result;
        }

        std::optional<int> undigitize(const std::vector<unsigned char>& digits)
        {
            size_t result = 0;

            for (unsigned char d : digits)
            {
                result *= 10;
                result += d;
            }

            if (result <= std::numeric_limits<int>::max())
                return static_cast<int>(result);

            return {};
        }

        std::optional<size_t> find_last_ascending(const std::vector<unsigned char>& digits)
        {
            for (size_t d = digits.size(); d >= 2; d--)
            {
                if (digits[d - 1] > digits[d - 2])
                    return d - 2;
            }
            return {};
        }
    };
}