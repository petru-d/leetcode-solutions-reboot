#include "pch.h"

#include "../problems/p122.h"

TEST(P122, T0)
{
    p122::Solution s;

    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 7);
}

TEST(P122, T1)
{
    p122::Solution s;

    std::vector<int> prices = {1, 2, 3, 4, 5};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 4);
}

TEST(P122, T2)
{
    p122::Solution s;

    std::vector<int> prices = {7, 6, 4, 3, 1};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 0);
}

TEST(P122, T3)
{
    p122::Solution s;

    std::vector<int> prices = {};
    int proffit = s.maxProfit(prices);
    EXPECT_EQ(proffit, 0);
}
