#include "pch.h"

#include "../problems/p65.h"

TEST(p65, t0)
{
    p65::Solution s;
    auto res = s.isNumber("123.123");
    EXPECT_TRUE(res);
}
