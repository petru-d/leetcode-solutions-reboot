#include "pch.h"

#include "../problems/p1286.h"

TEST(p1286, t0)
{
    p1286::CombinationIterator ci("abc", 2);

    auto res = ci.next();
    EXPECT_EQ(res, "ab");
    EXPECT_TRUE(ci.hasNext());

    res = ci.next();
    EXPECT_EQ(res, "ac");
    EXPECT_TRUE(ci.hasNext());

    res = ci.next();
    EXPECT_EQ(res, "bc");
    EXPECT_FALSE(ci.hasNext());
}
