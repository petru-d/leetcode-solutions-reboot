#include "pch.h"

#include "../problems/p96.h"

TEST(p96, t0)
{
    p96::Solution s;
    auto res = s.numTrees(3);

    EXPECT_EQ(res, 5);
}
