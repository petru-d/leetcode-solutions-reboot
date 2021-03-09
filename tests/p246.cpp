#include "pch.h"

#include "../problems/p246.h"

TEST(p246, t0)
{
    p246::Solution s;
    auto res = s.isStrobogrammatic("69");
    EXPECT_TRUE(res);
}
