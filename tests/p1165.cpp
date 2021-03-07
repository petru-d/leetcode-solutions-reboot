#include "pch.h"

#include "../problems/p1165.h"

TEST(p1165, t0)
{
    p1165::Solution s;
    auto res = s.calculateTime("abcdefghijklmnopqrstuvwxyz", "cba");
    EXPECT_EQ(res, 4);
}
