#include "pch.h"

#include "../problems/p201.h"

TEST(p201, t0)
{
    p201::Solution s;

    auto res = s.rangeBitwiseAnd(4, 7);
    EXPECT_EQ(res, 4);
}

TEST(p201, t1)
{
    p201::Solution s;

    auto res = s.rangeBitwiseAnd(0, 1);
    EXPECT_EQ(res, 0);
}

TEST(p201, t2)
{
    p201::Solution s;

    auto res = s.rangeBitwiseAnd(10, 11);
    EXPECT_EQ(res, 10);
}

TEST(p201, t3)
{
    p201::Solution s;

    auto res = s.rangeBitwiseAnd(5, 7);
    EXPECT_EQ(res, 4);
}