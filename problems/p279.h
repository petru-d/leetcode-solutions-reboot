#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

namespace p279
{
    class Solution
    {
      public:
        int numSquares(int n)
        {
            std::vector<int> min_sq(size_t(n) + 1, 0);
            std::vector<int> squares;

            // fill in the perfect squares. also test fast if n is a perfect square, in which care we return 1.
            for (size_t i = 1 + size_t(std::lround(sqrt(n))); i >= 1; --i)
            {
                auto sq = i * i;
                if (sq > n)
                    continue;
                if (sq == n)
                    return 1;
                min_sq[sq] = 1;
                squares.push_back(static_cast<int>(sq));
            }

            // fill in the sums of two squares. also test fast in n is a sum of perfect squares, in which care we return 2
            for (size_t s = squares.size(); s >= 1; --s)
                for (size_t t = squares.size(); t >= 1; --t)
                {
                    auto sum = squares[s - 1] + squares[t - 1];
                    if (sum > n)
                        break;
                    if (sum == n)
                        return 2;
                    if (min_sq[sum] == 0)
                        min_sq[sum] = 2;
                }

            // it's not 1 and it's not 2... it's either 3 or 4, since all integers can be expressed as a sum of at most 4 squares
            for (size_t i = 2; i <= size_t(n); ++i)
            {
                if (min_sq[i] == 1 || min_sq[i] == 2)
                    continue;

                min_sq[i] = 1 + min_sq[i - 1];
                if (min_sq[i] == 3)
                    goto cont;

                for (size_t s = 1; s < squares.size(); ++s)
                {
                    if (i <= squares[s])
                        break;
                    min_sq[i] = std::min(min_sq[i], 1 + min_sq[i - squares[s]]);
                    if (min_sq[i] == 3)
                        goto cont;
                }

            cont:
                continue;
            }

            return min_sq.back();
        }
    };
}
