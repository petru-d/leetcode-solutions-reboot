#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace p902
{
    class Solution
    {
      public:
        int atMostNGivenDigitSet(std::vector<std::string>& digits, int n)
        {
            std::vector<int> all_digits(digits.size(), 0);
            for (size_t i = 0; i < digits.size(); ++i)
                all_digits[i] = digits[i][0] - '0';
            std::sort(all_digits.begin(), all_digits.end());

            auto n_digits = get_digits(n);

            auto result = count_constraint(all_digits, n_digits);
            for (int i = 1; i <= n_digits.size() - 1; ++i)
                result += count_unconstraint(all_digits, i);

            return result;
        }

      private:
        std::vector<int> get_digits(int n)
        {
            std::vector<int> result;
            while (n != 0)
            {
                auto [q, r] = std::div(n, 10);
                result.push_back(r);
                n = q;
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

        // how many numbers of length l can form from the given digits (no constraints)
        int count_unconstraint(const std::vector<int>& digits, int l)
        {
            int result = 1;
            for (int i = 1; i <= l; ++i)
                result *= int(digits.size());

            return result;
        }

        // how many numbers of the length n_digits.size() can we form from the given digits, such that the formed numbers are all
        // less or equal to the number formed from n_digits
        // e.g. digits = {1, 3, 5}, n_digits = {1, 4, 3} -> we can form 111, 113, 115, 131, 133, 135 so 6 in total
        int count_constraint(const std::vector<int>& digits, const std::vector<int>& n_digits)
        {
            // how many digits are strictly smaller than the first digit (most significant) of n ?
            // do we have an equal digit?
            int count_less = 0;
            bool have_eq = false;
            for (const auto d : digits)
            {
                if (d < n_digits[0])
                    ++count_less;
                if (d == n_digits[0])
                    have_eq = true;
            }

            if (n_digits.size() == 1)
            {
                return count_less + int(have_eq);
            }

            // if the first digit is chosen to be strictly smaller than the most significant digit of n, then no constraint acts
            // on the rest
            int result = count_less * count_unconstraint(digits, int(n_digits.size()) - 1);
            if (!have_eq)
                return result;

            // we can also fix the first digit to be the most significant of n (if available), and check how many numbers can we
            // make that are <= then the rest of n
            std::vector<int> rest_digits;
            std::copy(n_digits.begin() + 1, n_digits.end(), std::back_inserter(rest_digits));

            result += count_constraint(digits, rest_digits);

            return result;
        }
    };
}
