#include "pch.h"

#include "../problems/p1143.h"

TEST(p1143, t0)
{
    p1143::Solution s;

    auto res = s.longestCommonSubsequence("abcde", "ace");

    EXPECT_EQ(res, 3);
}

TEST(p1143, t1)
{
    p1143::Solution s;

    auto res = s.longestCommonSubsequence("abc", "abc");

    EXPECT_EQ(res, 3);
}

TEST(p1143, t2)
{
    p1143::Solution s;

    auto res = s.longestCommonSubsequence("abc", "def");

    EXPECT_EQ(res, 0);
}

TEST(p1143, t3)
{
    p1143::Solution s;

    auto res = s.longestCommonSubsequence("bbm", "mb");

    EXPECT_EQ(res, 1);
}

TEST(p1143, t4)
{
    p1143::Solution s;

    auto res = s.longestCommonSubsequence("hofubmnylkra", "pqhgxgdofcvmr");

    EXPECT_EQ(res, 5);
}
