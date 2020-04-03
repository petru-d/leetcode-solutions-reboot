#include "pch.h"

#include "../problems/p76.h"

TEST(P76, T0)
{
    p76::Solution s;
    auto result = s.minWindow("abac", "ada");

    EXPECT_EQ(result, "");
}

TEST(P76, T1)
{
    p76::Solution s;
    auto result = s.minWindow("ADOBECODEBANC", "ABC");

    EXPECT_EQ(result, "BANC");
}
TEST(P76, T2)
{
    p76::Solution s;
    auto result = s.minWindow("ab", "b");

    EXPECT_EQ(result, "b");
}
TEST(P76, T3)
{
    p76::Solution s;
    auto result = s.minWindow("bba", "ab");

    EXPECT_EQ(result, "ba");
}
TEST(P76, T4)
{
    p76::Solution s;
    auto result = s.minWindow("aa", "aa");

    EXPECT_EQ(result, "aa");
}