#include "pch.h"

#include "../problems/p266.h"

TEST(p266, t0)
{
    p266::Solution s;

    auto res = s.canPermutePalindrome("aab");

    EXPECT_TRUE(res);
}
