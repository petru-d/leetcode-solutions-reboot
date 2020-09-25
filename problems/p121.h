#pragma once
#include <algorithm>
#include <vector>

namespace p121
{
    // my original solution
    /*class Solution
    {
        struct Action
        {
            size_t buy_here = size_t(-1);
            size_t sell_here = size_t(-1);
            bool valid() const
            {
                return buy_here != -1 && sell_here != -1;
            }
        };

      public:
        Action maxProfitOneTranzaction(std::vector<int>& prices, size_t start, size_t end)
        {
            if (end - start <= 1)
                return {};

            Action result{start, size_t(-1)};
            Action best_result = result;

            for (size_t p = start + 1; p < end; ++p)
            {
                if (prices[result.buy_here] < prices[p] && (result.sell_here == -1 || prices[result.sell_here] < prices[p]))
                {
                    result.sell_here = p;
                    if (!best_result.valid() || (prices[best_result.sell_here] - prices[best_result.buy_here] <
                                                 prices[result.sell_here] - prices[result.buy_here]))
                        best_result = result;
                }
                if (prices[p] < prices[result.buy_here])
                {
                    result = {p, size_t(-1)};
                }
            }

            return best_result;
        }

        int maxProfit(std::vector<int>& prices)
        {
            auto result = maxProfitOneTranzaction(prices, 0, prices.size());
            return result.valid() ? prices[result.sell_here] - prices[result.buy_here] : 0;
        }
    };*/

    // better solution, using dynamic programming
    class Solution
    {
      public:
        int maxProfit(std::vector<int>& prices)
        {
            size_t N = prices.size();
            if (N <= 1)
                return 0;

            int mini = prices[0];
            int maxi = prices[0];

            int max_proffit = 0;
            for (size_t i = 1; i < N; ++i)
            {
                mini = std::min(mini, prices[i]);
                max_proffit = std::max(max_proffit, prices[i] - mini);
            }

            return max_proffit;
        }
    };
}
