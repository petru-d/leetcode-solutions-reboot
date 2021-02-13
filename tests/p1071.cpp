#include "pch.h"

#include "../problems/p1071.h"

TEST(p1071, t0)
{
    p1071::Solution s;

    auto res = s.gcdOfStrings("ABCABC", "ABC");

    EXPECT_EQ(res, "ABC");
}
