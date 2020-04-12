#include "pch.h"

#include "../problems/p76.h"

TEST(p76, t0)
{
    p76::Solution s;
    auto result = s.minWindow("abac", "ada");

    EXPECT_EQ(result, "");
}

TEST(p76, t1)
{
    p76::Solution s;
    auto result = s.minWindow("ADOBECODEBANC", "ABC");

    EXPECT_EQ(result, "BANC");
}
TEST(p76, t2)
{
    p76::Solution s;
    auto result = s.minWindow("ab", "b");

    EXPECT_EQ(result, "b");
}
TEST(p76, t3)
{
    p76::Solution s;
    auto result = s.minWindow("bba", "ab");

    EXPECT_EQ(result, "ba");
}
TEST(p76, t4)
{
    p76::Solution s;
    auto result = s.minWindow("aa", "aa");

    EXPECT_EQ(result, "aa");
}