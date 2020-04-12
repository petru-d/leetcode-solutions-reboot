#include "pch.h"

#include "../problems/p844.h"

TEST(p844, t0)
{
    p844::Solution s;

    auto res = s.backspaceCompare("ab#c", "ad#c");
    EXPECT_EQ(res, true);
}

TEST(p844, t1)
{
    p844::Solution s;

    auto res = s.backspaceCompare("ab##", "c#d#");
    EXPECT_EQ(res, true);
}

TEST(p844, t2)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a##c", "#a#c");
    EXPECT_EQ(res, true);
}

TEST(p844, t3)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a#c", "b");
    EXPECT_EQ(res, false);
}

TEST(p844, t4)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a#c", "c");
    EXPECT_EQ(res, true);
}

TEST(p844, t5)
{
    p844::Solution s;

    auto res = s.backspaceCompare("nzp#o#g", "nzp#o##g");
    EXPECT_EQ(res, false);
}