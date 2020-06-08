#include "pch.h"

#include "../problems/p231.h"

TEST(p231, t0)
{
    p231::Solution s;
    auto res = s.isPowerOfTwo(4);
    EXPECT_TRUE(res);
}