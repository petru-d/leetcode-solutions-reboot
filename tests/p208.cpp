#include "pch.h"

#include "../problems/p208.h"

TEST(p208, t0)
{
    p208::Trie t;

    t.insert("apple");
    auto res = t.search("apple");
    EXPECT_EQ(res, true);

    res = t.search("app");
    EXPECT_EQ(res, false);

    res = t.startsWith("app");
    EXPECT_EQ(res, true);

    t.insert("app");
    res = t.search("app");
    EXPECT_EQ(res, true);
}
