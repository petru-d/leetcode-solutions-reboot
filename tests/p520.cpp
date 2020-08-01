#include "pch.h"

#include "../problems/p520.h"

TEST(p520, t0)
{
    p520::Solution s;

    auto res = s.detectCapitalUse("aX");

    EXPECT_FALSE(res);
}
