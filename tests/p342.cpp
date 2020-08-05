#include "pch.h"

#include "../problems/p342.h"

TEST(p342, t0)
{
    p342::Solution s;
    auto res = s.isPowerOfFour(1);
    EXPECT_TRUE(res);
}
