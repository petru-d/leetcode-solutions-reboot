#include "pch.h"

#include "../problems/p1446.h"

TEST(p1446, t0)
{
    p1446::Solution s;

    auto res = s.maxPower("leetcode");
    EXPECT_EQ(res, 2);
}
