#include "pch.h"

#include "../problems/p161.h"

TEST(p161, t0)
{
    p161::Solution s;

    auto res = s.isOneEditDistance("A", "B");
    EXPECT_TRUE(res);
}
