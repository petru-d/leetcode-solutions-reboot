#include "pch.h"

#include "../problems/p1663.h"

TEST(p1663, t0)
{
    p1663::Solution s;

    auto res = s.getSmallestString(3, 27);

    EXPECT_EQ(res, "aay");
}
