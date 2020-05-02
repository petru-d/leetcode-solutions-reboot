#include "pch.h"

#include "../problems/p1081.h"

TEST(p1081, t0)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("bcabc");
    EXPECT_EQ(res, "abc");
}

TEST(p1081, t1)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("cbacdcbc");
    EXPECT_EQ(res, "acdb");
}

TEST(p1081, t2)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("cdadabcc");
    EXPECT_EQ(res, "adbc");
}

TEST(p1081, t3)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("abcd");
    EXPECT_EQ(res, "abcd");
}

TEST(p1081, t4)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("ecbacba");
    EXPECT_EQ(res, "eacb");
}

TEST(p1081, t5)
{
    p1081::Solution s;
    auto res = s.smallestSubsequence("leetcode");
    EXPECT_EQ(res, "letcod");
}