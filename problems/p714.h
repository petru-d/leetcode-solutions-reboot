#pragma once
#include <algorithm>
#include <vector>

namespace p714
{
    class Solution
    {
      public:
        int maxProfit(std::vector<int>& prices, int fee)
        {
            int buy = 0;
            int sell = -prices[0];

            auto P = prices.size();
            for (size_t i = 0; i < P; ++i)
            {
                buy = std::max(buy, sell + prices[i] - fee);
                sell = std::max(sell, buy - prices[i]);
            }

            return buy;
        }
    };
}
