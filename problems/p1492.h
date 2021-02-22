#pragma once
#include <cmath>

namespace p1492
{
    class Solution
    {
      public:
        int kthFactor(int n, int k)
        {
            auto sqn = size_t(sqrt(n));

            std::vector<int> divs;
            divs.reserve(sqn);

            for (int i = 1; i <= sqn; ++i)
            {
                if (n % i == 0)
                {
                    divs.push_back(i);
                    if (--k == 0)
                        return i;
                }
            }

            bool square = (divs.back() * divs.back() == n);
            size_t totalDivs = divs.size() - size_t(square);

            if (k > totalDivs)
                return -1;

            return n / divs[totalDivs - k];
        }
    };
}
