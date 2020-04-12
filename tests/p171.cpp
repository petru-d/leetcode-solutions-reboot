#include "pch.h"

#include "../problems/p171.h"

TEST(p171, t0)
{
    p171::Solution s;

    EXPECT_EQ(1, s.titleToNumber("A"));
}

TEST(p171, t1)
{
    p171::Solution s;

    EXPECT_EQ(28, s.titleToNumber("AB"));
}

TEST(p171, t2)
{
    p171::Solution s;

    EXPECT_EQ(701, s.titleToNumber("ZY"));
}
