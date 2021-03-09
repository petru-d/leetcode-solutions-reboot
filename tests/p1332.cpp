#include "pch.h"

#include "../problems/p1332.h"

TEST(p1332, t0)
{
    p1332::Solution s;
    auto res = s.removePalindromeSub("aba");
    EXPECT_EQ(res, 1);
}
