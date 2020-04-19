#include "pch.h"

#include "../problems/p1328.h"

TEST(p1328, t0)
{
    p1328::Solution s;

    auto result = s.breakPalindrome("abccba");

    EXPECT_EQ(result, "aaccba");
}

TEST(p1328, t1)
{
    p1328::Solution s;

    auto result = s.breakPalindrome("a");

    EXPECT_EQ(result, "");
}

TEST(p1328, t2)
{
    p1328::Solution s;

    auto result = s.breakPalindrome("aba");

    EXPECT_EQ(result, "abb");
}