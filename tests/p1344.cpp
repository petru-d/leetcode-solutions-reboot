#include "pch.h"

#include "../problems/p1344.h"

TEST(p1344, t0)
{
    p1344::Solution s;
    auto res = s.angleClock(3, 15);

    EXPECT_NEAR(res, 7.5, 0.001);
}
