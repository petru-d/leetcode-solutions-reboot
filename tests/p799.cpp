#include "pch.h"

#include "../problems/p799.h"

TEST(p799, t0)
{
    p799::Solution s;

    auto res = s.champagneTower(2, 1, 1);

    EXPECT_NEAR(res, 0.5, 0.0001);
}

TEST(p799, t1)
{
    p799::Solution s;

    auto res = s.champagneTower(1, 1, 1);

    EXPECT_NEAR(res, 0, 0.0001);
}
