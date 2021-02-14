#include "pch.h"

#include "../problems/p1657.h"

TEST(p1657, t0)
{
    p1657::Solution s;
    auto res = s.closeStrings("cabbba", "abbccc");

    EXPECT_TRUE(res);
}
