#include "pch.h"

#include "../problems/p650.h"

TEST(p650, t0)
{
    p650::Solution s;
    auto res = s.minSteps(15);
    EXPECT_EQ(res, 8);
}