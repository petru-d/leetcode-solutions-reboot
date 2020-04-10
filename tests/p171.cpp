#include "pch.h"

#include "../problems/p171.h"

TEST(P171, T0)
{
    p171::Solution s;

    EXPECT_EQ(1, s.titleToNumber("A"));
}

TEST(P171, T1)
{
    p171::Solution s;

    EXPECT_EQ(28, s.titleToNumber("AB"));
}

TEST(P171, T2)
{
    p171::Solution s;

    EXPECT_EQ(701, s.titleToNumber("ZY"));
}
