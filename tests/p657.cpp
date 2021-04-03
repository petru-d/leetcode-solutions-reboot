#include "pch.h"

#include "../problems/p657.h"

TEST(p657, t0)
{
    p657::Solution s;
    auto res = s.judgeCircle("UD");
    EXPECT_TRUE(res);
}
