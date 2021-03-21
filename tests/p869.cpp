#include "pch.h"

#include "../problems/p869.h"

TEST(p869, t0)
{
    p869::Solution s;
    auto res = s.reorderedPowerOf2(46);
    EXPECT_TRUE(res);
}
