#pragma once
#include <vector>
namespace p122
{
    class Solution
    {
      public:
        int maxProfit(std::vector<int>& prices)
        {
            // states = [None, Bought]
            // if state == none, when on element i, look at element i + 1:
            //   - if p[i] >= p[i+1], do nothing
            //     else buy and state = buy.
            // if state == buy, when on element i, look at element i + 1:
            //   - if p[i] < p[i + 1], do nothing
            //     else sell and state = none

            enum class State
            {
                None,
                Bought
            };
            State state = State::None;
            int bought = 0;

            int proffit = 0;

            auto P = prices.size();
            for (size_t i = 0; i < P; ++i)
            {
                if (state == State::None)
                {
                    if (i != P - 1 && prices[i] < prices[i + 1])
                    {
                        state = State::Bought;
                        bought = prices[i];
                    }
                }
                else // if (state == State::Buy)
                {
                    if (i == P - 1 || prices[i] >= prices[i + 1])
                    {
                        state = State::None;
                        proffit += prices[i] - bought;
                    }
                }
            }

            return proffit;
        }
    };
}