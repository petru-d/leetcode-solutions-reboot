#include "pch.h"

#include "../problems/p1461.h"

TEST(p1461, t0)
{
    p1461::Solution s;

    auto res = s.hasAllCodes("01100", 2);
    EXPECT_TRUE(res);
}
