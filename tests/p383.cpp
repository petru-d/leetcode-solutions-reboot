#include "pch.h"

#include "../problems/p383.h"

TEST(p383, t0)
{
    p383::Solution s;

    auto res = s.canConstruct("a", "b");

    EXPECT_EQ(res, false);
}

TEST(p383, t1)
{
    p383::Solution s;

    auto res = s.canConstruct("aa", "ab");

    EXPECT_EQ(res, false);
}

TEST(p383, t2)
{
    p383::Solution s;

    auto res = s.canConstruct("aa", "aab");

    EXPECT_EQ(res, true);
}
