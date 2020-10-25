#include "pch.h"

#include "../problems/p188.h"

TEST(p188, t0)
{
    p188::Solution s;

    std::vector<int> prices = {2, 4, 1};

    auto res = s.maxProfit(2, prices);

    EXPECT_EQ(res, 2);
}

TEST(p188, t1)
{
    p188::Solution s;

    std::vector<int> prices = {3, 2, 6, 5, 0, 3};

    auto res = s.maxProfit(2, prices);

    EXPECT_EQ(res, 7);
}

TEST(p188, t2)
{
    p188::Solution s;

    std::vector<int> prices = {1, 2, 3, 2, 3, 4, 5, 6, 1, 5};

    auto res = s.maxProfit(100, prices);

    EXPECT_EQ(res, 10);
}
