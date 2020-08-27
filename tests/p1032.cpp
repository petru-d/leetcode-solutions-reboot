#include "pch.h"

#include "../problems/p1032.h"

TEST(p1032, t0)
{
    std::vector<std::string> words = {"cd", "f", "kl"};
    auto streamChecker = p1032::StreamChecker(words);

    auto res = streamChecker.query('a');
    EXPECT_FALSE(res);
    res = streamChecker.query('b');
    EXPECT_FALSE(res);
    res = streamChecker.query('c');
    EXPECT_FALSE(res);
    res = streamChecker.query('d');
    EXPECT_TRUE(res);
    res = streamChecker.query('e');
    EXPECT_FALSE(res);
    res = streamChecker.query('f');
    EXPECT_TRUE(res);
    res = streamChecker.query('g');
    EXPECT_FALSE(res);
    res = streamChecker.query('h');
    EXPECT_FALSE(res);
    res = streamChecker.query('i');
    EXPECT_FALSE(res);
    res = streamChecker.query('j');
    EXPECT_FALSE(res);
    res = streamChecker.query('k');
    EXPECT_FALSE(res);
    res = streamChecker.query('l');
    EXPECT_TRUE(res);
}
