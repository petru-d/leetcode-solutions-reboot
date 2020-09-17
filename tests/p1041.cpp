#include "pch.h"

#include "../problems/p1041.h"

TEST(p1041, t0)
{
    p1041::Solution s;

    auto res = s.isRobotBounded("GGLLGG");

    EXPECT_TRUE(res);
}
