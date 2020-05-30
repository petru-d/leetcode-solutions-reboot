#include "pch.h"

#include "../problems/p746.h"

TEST(p746, t0)
{
    p746::Solution s;

    std::vector<int> cost = {10, 15, 20};
    auto res = s.minCostClimbingStairs(cost);

    EXPECT_EQ(res, 15);
}

TEST(p746, t1)
{
    p746::Solution s;

    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    auto res = s.minCostClimbingStairs(cost);

    EXPECT_EQ(res, 6);
}