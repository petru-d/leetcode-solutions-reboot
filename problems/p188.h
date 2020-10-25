#pragma once
#include <algorithm>
#include <vector>

namespace p188
{
    class Solution
    {
      public:
        int maxProfit(int k, std::vector<int>& prices)
        {
            size_t P = prices.size();
            size_t K = size_t(k);

            if (P <= 1 || K == 0)
                return 0;

            if (K >= P / 2)
            {
                int proffit = 0;
                int low = prices[0];
                for (size_t i = 1; i < P; ++i)
                {
                    while (i < P && prices[i] >= prices[i - 1])
                        ++i;
                    proffit += prices[i - 1] - low;
                    if (i == P)
                        break;
                    low = prices[i];
                }

                return proffit;
            }

            std::vector<int> buys(K, std::numeric_limits<int>::max());
            std::vector<int> pros(K, 0);

            for (auto p : prices)
            {
                buys[0] = std::min(buys[0], p);
                pros[0] = std::max(pros[0], p - buys[0]);

                for (size_t i = 1; i < K; ++i)
                {
                    buys[i] = std::min(buys[i], p - pros[i - 1]);
                    pros[i] = std::max(pros[i], p - buys[i]);
                }
            }

            return pros.back();
        }
    };
}
