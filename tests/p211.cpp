#include "pch.h"

#include "../problems/p211.h"

TEST(p211, t0)
{
    p211::WordDictionary s;
    s.addWord("bad");
    s.addWord("dad");
    s.addWord("mad");

    auto res = s.search("pad");
    EXPECT_FALSE(res);

    res = s.search("bad");
    EXPECT_TRUE(res);

    res = s.search(".ad");
    EXPECT_TRUE(res);

    res = s.search("b..");
    EXPECT_TRUE(res);
}
