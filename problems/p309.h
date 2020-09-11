#pragma once

#include <algorithm>
#include <vector>

namespace p309
{
    class Solution
    {
      public:
        int maxProfit(std::vector<int>& prices)
        {
            if (prices.empty())
                return 0;

            std::vector<int> proffits(prices.size(), 0);
            proffits.back() = 0;

            for (int i = int(proffits.size()) - 2; i >= 0; --i)
            {
                if (prices[i + 1] < prices[i])
                    proffits[i] = proffits[i + 1];
                else
                {
                    proffits[i] = proffits[i + 1];
                    int k = 1;
                    while (i + k < prices.size() && prices[i + k] > prices[i])
                    {
                        int prev_proffit = i + k + 2 < proffits.size() ? proffits[i + k + 2] : 0;
                        proffits[i] = std::max(prev_proffit + prices[i + k] - prices[i], proffits[i]);
                        ++k;
                    }
                }
            }

            return proffits.front();
        }
    };
}
