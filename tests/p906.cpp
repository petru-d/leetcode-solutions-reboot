#include "pch.h"

#include "../problems/p906.h"

TEST(p906, t0)
{
    p906::Solution s;
    auto res = s.superpalindromesInRange("4", "1000");
    EXPECT_EQ(res, 4);
}
