#include "pch.h"

#include "../problems/p60.h"

TEST(p60, t0)
{
    p60::Solution s;

    auto res = s.getPermutation(3, 4);

    EXPECT_EQ(res, "231");
}

TEST(p60, t1)
{
    p60::Solution s;

    auto res = s.getPermutation(4, 9);

    EXPECT_EQ(res, "2314");
}
