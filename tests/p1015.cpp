#include "pch.h"

#include "../problems/p1015.h"

TEST(p1015, t0)
{
    p1015::Solution s;

    auto res = s.smallestRepunitDivByK(3);
    EXPECT_EQ(res, 3);
}
