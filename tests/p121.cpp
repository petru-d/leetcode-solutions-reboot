#include "pch.h"

#include "../problems/p121.h"

TEST(p121, t0)
{
    p121::Solution s;

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 5);
}

TEST(p121, t1)
{
    p121::Solution s;

    std::vector<int> prices = {7, 6, 4, 3, 1};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 0);
}

TEST(p121, t2)
{
    p121::Solution s;

    std::vector<int> prices = {3, 2, 6, 5, 0, 3};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 4);
}
