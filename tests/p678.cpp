#include "pch.h"

#include "../problems/p678.h"

TEST(p678, t0)
{
    p678::Solution s;

    auto res = s.checkValidString("()");
    EXPECT_EQ(res, true);
}

TEST(p678, t1)
{
    p678::Solution s;

    auto res = s.checkValidString("(*)");
    EXPECT_EQ(res, true);
}

TEST(p678, t2)
{
    p678::Solution s;

    auto res = s.checkValidString("(*))");
    EXPECT_EQ(res, true);
}

TEST(p678, t3)
{
    p678::Solution s;

    auto res = s.checkValidString("())");
    EXPECT_EQ(res, false);
}

TEST(p678, t4)
{
    p678::Solution s;

    auto res = s.checkValidString("*))");
    EXPECT_EQ(res, false);
}

TEST(p678, t5)
{
    p678::Solution s;

    auto res = s.checkValidString("*()(())*()(()()((()(()()*)(*(())((((((((()*)(()(*)");
    EXPECT_EQ(res, false);
}

TEST(p678, t6)
{
    p678::Solution s;

    auto res = s.checkValidString("**((((*)(*((((((((*)");
    EXPECT_EQ(res, false);
}
