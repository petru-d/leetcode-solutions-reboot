#include "pch.h"

#include "../problems/p322.h"

TEST(p322, t0)
{
    p322::Solution s;

    std::vector<int> coins = {1, 2, 5};
    auto res = s.coinChange(coins, 11);

    EXPECT_EQ(res, 3);
}

TEST(p322, t1)
{
    p322::Solution s;

    std::vector<int> coins = {2};
    auto res = s.coinChange(coins, 3);

    EXPECT_EQ(res, -1);
}

TEST(p322, t2)
{
    p322::Solution s;

    std::vector<int> coins = {1, 2, 5};
    auto res = s.coinChange(coins, 100);

    EXPECT_EQ(res, 20);
}