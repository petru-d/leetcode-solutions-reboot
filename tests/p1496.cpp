#include "pch.h"

#include "../problems/p1496.h"

TEST(p1496, t0)
{
    p1496::Solution s;

    auto res = s.isPathCrossing("NESWW");
    EXPECT_TRUE(res);
}
