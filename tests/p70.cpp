#include "pch.h"

#include "../problems/p70.h"

TEST(p70, t0)
{
    p70::Solution s;
    auto res = s.climbStairs(5);
    EXPECT_EQ(res, 8);
}