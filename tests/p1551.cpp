#include "pch.h"

#include "../problems/p1551.h"

TEST(p1551, t0)
{
    p1551::Solution s;
    auto res = s.minOperations(3);
    EXPECT_EQ(res, 2);
}
