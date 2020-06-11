#include "pch.h"

#include "../problems/p279.h"

TEST(p279, t0)
{
    p279::Solution s;

    auto res = s.numSquares(12);
    EXPECT_EQ(res, 3);
}
