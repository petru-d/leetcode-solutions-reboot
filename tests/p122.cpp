#include "pch.h"

#include "../problems/p122.h"

TEST(p122, t0)
{
    p122::Solution s;

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 7);
}

TEST(p122, t1)
{
    p122::Solution s;

    std::vector<int> prices = {1, 2, 3, 4, 5};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 4);
}

TEST(p122, t2)
{
    p122::Solution s;

    std::vector<int> prices = {7, 6, 4, 3, 1};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 0);
}

TEST(p122, t3)
{
    p122::Solution s;

    std::vector<int> prices = {};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 0);
}
