#include "pch.h"

#include "../problems/p1492.h"

TEST(p1492, t0)
{
    p1492::Solution s;
    auto res = s.kthFactor(12, 3);

    EXPECT_EQ(res, 3);
}
