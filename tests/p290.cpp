#include "pch.h"

#include "../problems/p290.h"

TEST(p290, t0)
{
    p290::Solution s;

    auto res = s.wordPattern("abba", "dog cat cat dog");

    EXPECT_TRUE(res);
}

TEST(p290, t1)
{
    p290::Solution s;

    auto res = s.wordPattern("abba", "dog dog dog dog");

    EXPECT_FALSE(res);
}

TEST(p290, t2)
{
    p290::Solution s;

    auto res = s.wordPattern("abba", "dog cat cat fish");

    EXPECT_FALSE(res);
}

TEST(p290, t3)
{
    p290::Solution s;

    auto res = s.wordPattern("aaa", "aa aa aa aa");

    EXPECT_FALSE(res);
}
