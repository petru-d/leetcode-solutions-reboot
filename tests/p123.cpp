#include "pch.h"

#include "../problems/p123.h"

TEST(p123, t0)
{
    p123::Solution s;
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 6);
}

TEST(p123, t1)
{
    p123::Solution s;
    std::vector<int> prices = {1, 2, 3, 4, 5};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 4);
}

TEST(p123, t2)
{
    p123::Solution s;
    std::vector<int> prices = {7, 6, 4, 3, 1};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 0);
}

TEST(p123, t3)
{
    p123::Solution s;
    std::vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 13);
}

TEST(p123, t4)
{
    p123::Solution s;
    std::vector<int> prices = {8, 6, 4, 3, 3, 2, 3, 5, 8, 3, 8, 2, 6};

    auto res = s.maxProfit(prices);

    EXPECT_EQ(res, 11);
}
