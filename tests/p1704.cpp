#include "pch.h"

#include "../problems/p1704.h"

TEST(p1704, t0)
{
    p1704::Solution s;
    auto res = s.halvesAreAlike("aa");
    EXPECT_TRUE(res);
}
