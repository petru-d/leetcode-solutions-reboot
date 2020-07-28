#include "pch.h"

#include "../problems/p1154.h"

TEST(p1154, t0)
{
    p1154::Solution s;

    auto res = s.dayOfYear("2019-01-09");

    EXPECT_EQ(res, 9);
}
