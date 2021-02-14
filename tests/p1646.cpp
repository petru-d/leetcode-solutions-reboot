#include "pch.h"

#include "../problems/p1646.h"

TEST(p1646, t0)
{
    p1646::Solution s;

    auto res = s.getMaximumGenerated(7);

    EXPECT_EQ(res, 3);
}
