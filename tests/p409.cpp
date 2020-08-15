#include "pch.h"

#include "../problems/p409.h"

TEST(p409, t0)
{
    p409::Solution s;
    auto res = s.longestPalindrome("abccccdd");
    EXPECT_EQ(res, 7);
}
