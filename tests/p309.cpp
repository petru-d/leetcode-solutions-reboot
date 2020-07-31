#include "pch.h"

#include "../problems/p309.h"

TEST(p309, t0)
{
    p309::Solution s;

    std::vector<int> prices = {1, 2, 3, 0, 2};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 3);
}

TEST(p309, t1)
{
    p309::Solution s;

    std::vector<int> prices = {2, 4, 1, 7};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 6);
}
