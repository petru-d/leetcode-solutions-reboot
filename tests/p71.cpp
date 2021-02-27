#include "pch.h"

#include "../problems/p71.h"

TEST(p71, t0)
{
    p71::Solution s;
    auto res = s.simplifyPath("/home/");

    EXPECT_EQ(res, "/home");
}
