#pragma once

#include <vector>

namespace p518
{
    class Solution
    {
      public:
        int change(int amount, std::vector<int>& coins)
        {
            if (coins.empty())
                return int(0 == amount);

            std::vector<int> prev_combs_c(1 + size_t(amount), 0);
            prev_combs_c[0] = 1;
            for (size_t i = 1; i < prev_combs_c.size(); ++i)
            {
                prev_combs_c[i] = int(i % coins[0] == 0);
            }
            auto combs_c = prev_combs_c;

            for (size_t c = 1; c < coins.size(); ++c)
            {
                combs_c[0] = 1;
                for (size_t i = 1; i < combs_c.size(); ++i)
                    combs_c[i] = prev_combs_c[i] + (i >= coins[c] ? combs_c[i - coins[c]] : 0);

                std::swap(prev_combs_c, combs_c);
            }

            return prev_combs_c.back();
        }
    };
}