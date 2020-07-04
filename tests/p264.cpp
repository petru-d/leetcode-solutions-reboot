#include "pch.h"

#include "../problems/p264.h"

TEST(p264, t0)
{
    p264::Solution s;
    auto res = s.nthUglyNumber(10);

    EXPECT_EQ(res, 12);
}
