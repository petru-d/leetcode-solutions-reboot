#include "pch.h"

#include "../problems/p1044.h"

TEST(p1044, t0)
{
    p1044::Solution s;

    auto res = s.longestDupSubstring("banana");

    EXPECT_EQ(res, "ana");
}
