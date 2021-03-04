#include "pch.h"

#include "../problems/p991.h"

TEST(p991, t0)
{
    p991::Solution s;
    auto res = s.brokenCalc(2, 3);
    EXPECT_EQ(res, 2);
}
