#pragma once
#include <cassert>
#include <numeric>
#include <unordered_set>
#include <vector>

namespace p202
{
    class Solution
    {
      public:
        bool isHappy(int n)
        {
            auto digits = digitize(n);

            std::unordered_set<int> path = {n};

            // do the digit thing. if the result is 1 or 10 or 100 or .., return happy.
            // if going back to where we were, return unhappy
            while (true)
            {
                n = sum_digit_squares(digits);
                if (n == 1 || n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000 || n == 1000000 || n == 10000000 ||
                    n == 100000000 || n == 1000000000)
                    return true;

                auto pos = path.find(n);
                if (pos != path.end())
                    return false;

                path.insert(n);
                digits = digitize(n);
            }
        }

      private:
        // return the digits (ignore zeros, they don't matter)
        std::vector<unsigned char> digitize(int n)
        {
            std::vector<unsigned char> digits;
            digits.reserve(10);
            while (n != 0)
            {
                auto qr = lldiv(n, 10);
                if (qr.rem != 0)
                    digits.push_back(static_cast<unsigned char>(qr.rem));
                n = static_cast<int>(qr.quot);
            }

            return digits;
        }

        int sum_digit_squares(const std::vector<unsigned char>& digits)
        {
            return std::accumulate(digits.begin(), digits.end(), 0, [](int acc, int curr) { return acc + curr * curr; });
        }
    };
}