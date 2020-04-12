#include "pch.h"

#include "../problems/p367.h"

TEST(p367, t0)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(4);

    EXPECT_EQ(result, true);
}

TEST(p367, t1)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(16);

    EXPECT_EQ(result, true);
}

TEST(p367, t2)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(14);

    EXPECT_EQ(result, false);
}

TEST(p367, t3)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2147483647);

    EXPECT_EQ(result, false);
}

TEST(p367, t4)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2);

    EXPECT_EQ(result, false);
}

TEST(p367, t5)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2147395600);

    EXPECT_EQ(result, true);
}