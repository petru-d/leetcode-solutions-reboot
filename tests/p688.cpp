#include "pch.h"

#include "../problems/p688.h"

TEST(p688, t0)
{
    p688::Solution s;

    auto res = s.knightProbability(3, 2, 0, 0);

    EXPECT_NEAR(res, 0.0625, 0.001);
}
