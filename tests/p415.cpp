#include "pch.h"

#include "../problems/p415.h"

TEST(p415, t0)
{
    p415::Solution s;
    auto res = s.addStrings("11", "123");
    EXPECT_EQ(res, "134");
}
