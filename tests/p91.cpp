#include "pch.h"

#include "../problems/p91.h"

TEST(p91, t0)
{
    p91::Solution s;

    auto res = s.numDecodings("12");

    EXPECT_EQ(res, 2);
}
