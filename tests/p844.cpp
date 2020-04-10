#include "pch.h"

#include "../problems/p844.h"

TEST(P844, T0)
{
    p844::Solution s;

    auto res = s.backspaceCompare("ab#c", "ad#c");
    EXPECT_EQ(res, true);
}

TEST(P844, T1)
{
    p844::Solution s;

    auto res = s.backspaceCompare("ab##", "c#d#");
    EXPECT_EQ(res, true);
}

TEST(P844, T2)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a##c", "#a#c");
    EXPECT_EQ(res, true);
}

TEST(P844, T3)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a#c", "b");
    EXPECT_EQ(res, false);
}

TEST(P844, T4)
{
    p844::Solution s;

    auto res = s.backspaceCompare("a#c", "c");
    EXPECT_EQ(res, true);
}

TEST(P844, T5)
{
    p844::Solution s;

    auto res = s.backspaceCompare("nzp#o#g", "nzp#o##g");
    EXPECT_EQ(res, false);
}