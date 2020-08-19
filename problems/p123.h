#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

namespace p123
{
    class Solution
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

        int getProffit(const std::vector<int>& prices, const Action& action)
        {
            if (!action.valid())
                return 0;

            return prices[action.sell_here] - prices[action.buy_here];
        }

      public:
        int maxProfit2(std::vector<int>& prices)
        {
            size_t P = prices.size();
            if (P <= 1)
                return 0;

            auto actionLeft = maxProfitOneTranzaction(prices, 0, P);
            Action actionRight = {};

            int result = getProffit(prices, actionLeft);
            for (size_t i = P - 1; i >= 1; --i)
            {
                // [0  i) and [i, P - 1)
                if (actionLeft.valid() && actionLeft.sell_here >= i)
                    actionLeft = maxProfitOneTranzaction(prices, 0, i);

                if (i < P - 1 && prices[i] < prices[i + 1])
                    actionRight = maxProfitOneTranzaction(prices, i, P);

                result = std::max(result, getProffit(prices, actionLeft) + getProffit(prices, actionRight));
            }

            return result;
        }

        int maxProfit(std::vector<int>& prices)
        {
            int firstBuy = std::numeric_limits<int>::max();
            int secondBuy = std::numeric_limits<int>::max();
            int firstProfit = 0;
            int secondProfit = 0;
            for (int currPrice : prices)
            {
                firstBuy = std::min(firstBuy, currPrice);
                firstProfit = std::max(firstProfit, currPrice - firstBuy);
                secondBuy = std::min(secondBuy, currPrice - firstProfit);
                secondProfit = std::max(secondProfit, currPrice - secondBuy);

                int x = 0;
            }
            return secondProfit;
        }
    };
}
