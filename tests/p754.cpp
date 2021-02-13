#include "pch.h"

#include "../problems/p754.h"

TEST(p754, t0)
{
    p754::Solution s;

    auto res = s.reachNumber(3);

    EXPECT_EQ(res, 2);
}
