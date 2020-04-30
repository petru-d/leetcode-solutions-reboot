#include "pch.h"

#include "../problems/p453.h"

TEST(p453, t0)
{
    std::vector<int> nums = {1, 2, 3};

    p453::Solution s;
    auto res = s.minMoves(nums);
    EXPECT_EQ(res, 3);
}

TEST(p453, t1)
{
    std::vector<int> nums = {5, 6, 8, 8, 5};

    p453::Solution s;
    auto res = s.minMoves(nums);
    EXPECT_EQ(res, 7);
}
